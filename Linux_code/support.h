#ifndef SUPPORT_H_
#define SUPPORT_H_

#include "fgnet.h"

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stdio.h>
#include <linux/i2c-dev.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <time.h>
#include <pthread.h> 
#include <stdbool.h> 

#define MAXACCEL 32768/2
#define ARRAYSIZE 20

#define FG_PORT 5500
#define SERVER_PORT 5600
#define MAXLINE 1024


static void htond (double *x);
static void htonf (float *x);
void dealwithFGNET(FGNetFDM * fgm_buf);

// =============== BEGIN STUDENT HEADER CONTENT ================

// Struct to hold roll, pitch, and speed data as well as mutex 
typedef struct{
	float roll;
	float pitch;
	float speed; 
} control_data; 

typedef struct{
	control_data* control;             // The control data calculated using psoc input 
	pthread_mutex_t  control_mutex;    // Mutex protecting control_cond 

} reader_input; 

// ================ END STUDENT HEADER CONTENT ================


#endif
