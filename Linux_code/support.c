#include "fgnet.h"
#include "support.h"

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <linux/i2c-dev.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <time.h>

#define FG_PORT 5500
#define SERVER_PORT 5600
#define MAXLINE 1024


// ========================== BEGIN STUDENT CODE ===========================
// e.g. helper functions as needed
// ======================= END STUDENT CODE ================================

// --------------------- BEGIN FLIGHTGEAR SUPPORT CODE ---------------------
static void htond (double *x) {
    int    *Double_Overlay;
    int     Holding_Buffer;

    Double_Overlay = (int *) x;
    Holding_Buffer = Double_Overlay [0];

    Double_Overlay [0] = htonl (Double_Overlay [1]);
    Double_Overlay [1] = htonl (Holding_Buffer);
}

static void htonf (float *x) {
//	if ( sgIsLittleEndian() ) {
		int    *Float_Overlay;
		int     Holding_Buffer;

		Float_Overlay = (int *) x;
		Holding_Buffer = Float_Overlay [0];

		Float_Overlay [0] = htonl (Holding_Buffer);
}


void dealwithFGNET(FGNetFDM * fgm_buf) {

	    htond(&fgm_buf->latitude);
	    htond(&fgm_buf->longitude);
	    htond(&fgm_buf->altitude);
	    htonf(&fgm_buf->agl);
	    htonf(&fgm_buf->phi);
	    htonf(&fgm_buf->psi);
	    htonf(&fgm_buf->theta);
	    htonf(&fgm_buf->alpha);    // 0
	    htonf(&fgm_buf->beta);     // 0

	    //velocities
	    htonf(&fgm_buf->phidot);   // 0
	    htonf(&fgm_buf->thetadot); // 0
	    htonf(&fgm_buf->psidot);   // 0
	    htonf(&fgm_buf->vcas);
	    htonf(&fgm_buf->climb_rate);
	    htonf(&fgm_buf->v_north);
	    htonf(&fgm_buf->v_east);
	    htonf(&fgm_buf->v_down);
	    htonf(&fgm_buf->v_body_u);
	    htonf(&fgm_buf->v_body_v);
	    htonf(&fgm_buf->v_body_w);

	    htonf(&fgm_buf->A_X_pilot);
	    htonf(&fgm_buf->A_Y_pilot);
	    htonf(&fgm_buf->A_Z_pilot);

	    htonf(&fgm_buf->stall_warning);
	    htonf(&fgm_buf->slip_deg);

	    fgm_buf->num_engines = htonl(fgm_buf->num_engines);
	    for (int i = 0; i < fgm_buf->num_engines; i++) {
	      fgm_buf->eng_state[i] = htonl(fgm_buf->eng_state[i]);
	      htonf(&fgm_buf->fuel_flow[i]);
	      htonf(&fgm_buf->fuel_px[i]);
	      htonf(&fgm_buf->egt[i]);
	      htonf(&fgm_buf->cht[i]);
	      htonf(&fgm_buf->mp_osi[i]);
	      htonf(&fgm_buf->tit[i]);
	      htonf(&fgm_buf->oil_temp[i]);
	      htonf(&fgm_buf->oil_px[i]);
	    }
	    fgm_buf->num_engines = htonl(fgm_buf->num_engines);

	    fgm_buf->num_tanks = htonl(fgm_buf->num_tanks);
	    for (int i = 0; i < fgm_buf->num_tanks; i++) {
	      htonf(&fgm_buf->fuel_quantity[i]);
	    }
	    fgm_buf->num_tanks = htonl(fgm_buf->num_tanks);

	    fgm_buf->num_wheels = htonl(fgm_buf->num_wheels);
	    for (int i = 0; i < fgm_buf->num_wheels; i++) {
	      fgm_buf->wow[i] = htonl(fgm_buf->wow[i]);
	      htonf(&fgm_buf->gear_pos[i]);
	      htonf(&fgm_buf->gear_steer[i]);
	      htonf(&fgm_buf->gear_compression[i]);
	    }
	    fgm_buf->num_wheels = htonl(fgm_buf->num_wheels);

	    fgm_buf->cur_time = htonl(time(NULL));

	    fgm_buf->warp = htonl(fgm_buf->warp);
	    htonf(&fgm_buf->visibility);

	    htonf(&fgm_buf->elevator);
	    htonf(&fgm_buf->elevator_trim_tab);
	    htonf(&fgm_buf->left_flap);
	    htonf(&fgm_buf->right_flap);
	    htonf(&fgm_buf->left_aileron);
	    htonf(&fgm_buf->right_aileron);
	    htonf(&fgm_buf->rudder);
	    htonf(&fgm_buf->nose_wheel);
	    htonf(&fgm_buf->speedbrake);
	    htonf(&fgm_buf->spoilers);
}
// ---------------------- END FLIGHTGEAR SUPPORT CODE ----------------------
