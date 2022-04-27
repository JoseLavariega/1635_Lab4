#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // open
#include <math.h>
#include "support.h"
#define TIMESTEP 0.01
#define YAW_CONST 0.2
#define RADIUS 6371000
#define MAX_SPEED 500
#define MIN_SPEED 100

void* readerThread(void * input_params) {

  //configure port start
  char *portname = "/dev/ttyACM0";
  struct termios options;
  int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
  if (fd < 0)
  {
    printf("failed to open port\n");
  }
  tcgetattr(fd, &options);
  cfsetospeed(&options, B115200);
  cfsetispeed(&options, B115200);
  tcsetattr(fd, TCSANOW, &options);
  close(fd);
  
  //configure port end
  FILE* fp = fopen(portname, "r");

  // Access shared data 
  reader_input* shared_data = (reader_input*) input_params; 
  
  // Initialize values 
  float acc_x, acc_y,acc_z, speed, acc_x_sqrd,acc_y_sqrd,acc_z_sqrd,sqrd;
  float norm_acc_x, norm_acc_y, norm_acc_z, totalAccelMagnitude;
  float roll,pitch; 
  
  // Input string. Throw out first reading 
  char input_str[512]; 
  int n = fscanf(fp, " %s end \r\n",&input_str);
  
  
  while(true){

  	// Reinitialize input string 
  	char input_str[512]; 
  	
  	// Rewind to capture full output 
  	rewind(fp);
  	
  	// Scan port 
    	int n = fscanf(fp, " %s end \r\n",&input_str);
  	
  	// Go through the string and store new values 
  	char* token = strtok(input_str,",");
  	float input_nums[4];
  	int i = 0; 
  	
  	while(token != NULL & i < 4){
  	
  		input_nums[i]= strtof(token,NULL);
  		i++;
  		token = strtok(NULL,","); 
  	}
  	
  	// Assign accelerometer and speed data
  	acc_x = input_nums[0];
  	acc_y = input_nums[1];
  	acc_z = input_nums[2];
  	speed = input_nums[3]; 
  	
  	// Constrain speed to within min and max
  	speed = speed < MIN_SPEED? MIN_SPEED : speed;  // speed must be at least min speed 
  	speed = speed > MAX_SPEED? MAX_SPEED : speed;  // speed must be at most max speed
  	
  	printf("<reader> Acc_x: %f\n", acc_x);
  	printf("<reader> Acc_y: %f\n", acc_y);
  	printf("<reader> Acc_z: %f\n", acc_z);
  	printf("<reader> Speed: %f\n", speed); 
  	
  	// Square accelerometer data 
  	acc_x_sqrd = pow(acc_x,2);
  	acc_y_sqrd = pow(acc_y,2);
  	acc_z_sqrd = pow(acc_z,2);
  	
  	// Normalize accelerometer data 
  	totalAccelMagnitude = sqrt(acc_x_sqrd + acc_y_sqrd + acc_z_sqrd); 
  	norm_acc_x = acc_x/totalAccelMagnitude;
  	norm_acc_y = acc_y/totalAccelMagnitude;
  	norm_acc_z = acc_z/totalAccelMagnitude; 
  	
  	// Calculate pitch and roll in radians 
  	pitch = -asin(norm_acc_x); 
  	roll = asin(norm_acc_y/cos(pitch));
  	
  	printf("<reader> pitch: %f\n", pitch);
  	printf("<reader> roll: %f\n", roll);
  	
  	///////////////////// Critical Region ////////////////////////
  	
  	// Get mutex 
  	pthread_mutex_lock(&(shared_data->control_mutex)); 
  	
  	printf("<reader> Storing values\n");
  	// Store values in shared data 
  	shared_data->control->speed = speed; 
  	shared_data->control->pitch = pitch;
  	shared_data->control->roll = roll; 
  	
  	// Release mutex
  	printf("<reader> releasing mutex\n");
  	pthread_mutex_unlock(&(shared_data->control_mutex)); 
  
  	/////////////////// End of Critical Region //////////////////
  	
  	
  }

  
  // ====================== BEGIN STUDENT CODE ================================
  // handle input parameters if necessary (or put above)
  // scan the file for the necessary information.
  // (if desired, compute a rolling average of accelerometer data for smoothing)
  // compute roll, pitch, and speed.
  // store values for access by main thread.
  // ====================== END STUDENT CODE ================================

  fclose(fp);
}

int main() {
  // ======================== BEGIN STUDENT CODE =============================
  // Handle threading and launch the reader thread
  
  // Create thread and inputs to thread 
  pthread_t reader_thread; 
  control_data* control = malloc(sizeof(control_data)); 
  reader_input* thread_input = malloc(sizeof(reader_input)); 
  
  // Initialize fields in thread input
  thread_input->control = control; 
  pthread_mutex_init(&(thread_input->control_mutex), NULL);
  
  
  // Launch reader thread 
  pthread_create(&reader_thread, NULL, readerThread, (void*) thread_input); 

  // ========================= END STUDENT CODE ==============================

  //------------------------- begin flightgear code --------------------------
  
  FGNetFDM fgm_buf, prev_buf;
  char* buff_in = (char*) &fgm_buf;

	int fg_socket, me_socket, fg_len, me_len;
	struct sockaddr_in fg_server, my_server, from;

	memset(&fg_server, 0, sizeof(fg_server));
  memset(&my_server, 0, sizeof(my_server));
	memset(&fgm_buf, 0, sizeof(fgm_buf));

	fg_socket = socket(AF_INET, SOCK_DGRAM, 0);
	fg_server.sin_addr.s_addr = inet_addr("127.0.0.1");
	fg_server.sin_family = AF_INET;
	fg_server.sin_port = htons(FG_PORT);

  me_socket = socket(AF_INET, SOCK_DGRAM, 0);
  my_server.sin_addr.s_addr = inet_addr("127.0.0.1"); //INADDR_ANY;
  my_server.sin_family = AF_INET;
  my_server.sin_port = htons(SERVER_PORT);


  bind(me_socket, (struct sockaddr*)&my_server, sizeof(my_server));

  me_len = sizeof(my_server);
  
  printf("<main> Waiting for bytes to receive from fgm...\n");
  int bytes_received = recvfrom(me_socket, &fgm_buf, sizeof(fgm_buf), 0, (struct sockaddr*)&from, &me_len);
  if (bytes_received < 0) {
    perror("recvfrom");
  }

  connect(fg_socket, (struct sockaddr*)&fg_server, sizeof(fg_server));

  prev_buf.altitude = 152.4;
  prev_buf.latitude = 2.66680;
  prev_buf.longitude = 0.24000;
  prev_buf.psi = 0.0;
  //------------------------- end flightgear code --------------------------

  float phi, theta, psi, speed;

  while (1) {
    dealwithFGNET(&fgm_buf);

    // ===================== BEGIN STUDENT CODE ===============================

    
    ///////////////////// Critical Region ////////////////////////
    pthread_mutex_lock(&(thread_input->control_mutex));
    
    // Access data 
    phi = thread_input->control->roll;
    theta = thread_input->control->pitch;
    speed = thread_input->control->speed;
    
    printf("********************************");
    printf("<main> roll: %f\n", phi);
    printf("<main> pitch: %f\n", theta);
    printf("<main> speed: %f\n", speed); 
    
    pthread_mutex_unlock(&(thread_input->control_mutex)); 
    /////////////////// End of Critical Region //////////////////
    
    // ===================== END STUDENT CODE ===============================


    // What follows are very simplified dynamics.

    // a yaw calculation
    psi = prev_buf.psi + YAW_CONST*sin(phi) * TIMESTEP;   // yaw related to roll
    psi = (psi < 0) ? 2*M_PI + psi : (psi < 2*M_PI) ? psi : 0;  // bound psi

    // rotation matrix
    float T_col1[3] = {cos(psi) * cos(theta), sin(psi)*cos(theta), -sin(theta)};

    float T_col2[3] = {cos(psi) * sin(theta) * sin(phi) - sin(psi)*cos(phi), \
      sin(psi) * sin(theta) * sin(phi) + cos(psi)*cos(phi), cos(theta)*sin(phi)};

    float T_col3[3] = {cos(psi)*sin(theta)*cos(phi)+sin(psi)*sin(phi), \
      sin(psi)*sin(theta)*cos(phi)-cos(psi)*sin(phi), cos(theta)*cos(phi)};


    // set new position and orientation (very approximate)
    fgm_buf.altitude -= (T_col1[2]*speed ) * TIMESTEP;
    fgm_buf.latitude += atan2((T_col1[0]*speed) * TIMESTEP, RADIUS);
    fgm_buf.longitude += atan2((T_col1[1]*speed ) * TIMESTEP, RADIUS);
    fgm_buf.phi = phi;
    fgm_buf.theta = theta;
    fgm_buf.psi = psi;

    // store old position and orientation
    prev_buf.altitude = fgm_buf.altitude;
    prev_buf.latitude = fgm_buf.latitude;
    prev_buf.longitude = fgm_buf.longitude;
    prev_buf.psi = fgm_buf.psi;

    fgm_buf.agl = fgm_buf.altitude; // above ground level
    fgm_buf.cur_time = htonl(time(NULL));
    dealwithFGNET(&fgm_buf);
    sendto(fg_socket, (char*) &fgm_buf, sizeof(fgm_buf), 0, (struct sockaddr*)&fg_server, sizeof(fg_server));

    usleep(10000);
  }

  close(fg_socket);
  // and join thread
  pthread_join(reader_thread,NULL);
}
