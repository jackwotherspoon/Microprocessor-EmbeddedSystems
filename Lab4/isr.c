#include "nios2_control.h"

#include "leds.h"

#include "timer.h"
#include "chario.h"



int HexConv[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

int min_10 = 0;

int min_1 = 0;

int sec_10 = 0;

int sec_1 = 0;

int dispval = 0;

int run = 1;

int flag;

int state=4;

int shift=9;


void HandleOrigTimer(void){

	sec_1++; // increment sec

	flag = 1;

	if(sec_1 > 9){ 

		sec_1 = 0;// increment 10 of sec

		sec_10++;

		if(sec_10 > 5){

			sec_10 = 0; //increment min

			min_1++;

			if(min_1 > 9){

				min_1 = 0; //increment 10 min

				min_10++;

				if(min_10 > 5){

					min_10 = 0; //if we hit an hour reset

				}

			}

		}

	}

	dispval = 0; // clear the variable contents

	//display the appropriate number in the correct hex display.

	dispval = HexConv[sec_1] | (HexConv[sec_10] << 8) | (HexConv[min_1] << 16) | (HexConv[min_10] << 24);

	

}




void interrupt_handler(void)

{

	unsigned int ipending;


	/* read current value in ipending register */

	ipending = NIOS2_READ_IPENDING();

//printString("got in isr \n");


	if((ipending & 1)){

		*TIMER_STATUS = 0;

		flag = 1;
		//HandleOrigTimer();

	}

	if((ipending & 2)){

		*BUTTONS_EDGE = 0;
		state = 4;
		shift = 9;
		

	} 	
	

	if ((ipending & (0x1<<13))){
		

		*T0_STATUS = 0;

		state =state+1;
		
		if (state > 4){
			shift+= 1;
			state = 0;
		}
		
		if (shift>9){
		shift = 0;
		
		}
		
		*LEDS = 0;
		*LEDS = *LEDS ^(state%2<< shift);

	}

	

	
}

