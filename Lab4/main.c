#include "adc.h"

#include "chario.h"

#include "timer.h"

#include "leds.h"



#include "nios2_control.h"





void initTimer (void)

{

  /* initialize software variables */

	//*LEDS = (12 << 6)| 1;
	

	*BUTTONS_EDGE = 0;

	*BUTTONS_MASK = 0x2;



  /* set timer start value for interval of HALF SECOND (0.5 sec) */

	*TIMER_START_HI = 0x02FA;

	*TIMER_START_LO = 0xF080;

	*T0_START_HI = 0x70;

	*T0_START_LO = 0xA120;

	

  /* clear extraneous timer interrupt */

  *TIMER_STATUS= 0;

  *T0_STATUS= 1;





  /* set ITO, CONT, and START bits of timer control register */

  *TIMER_CONTROL = 0x7;

  *T0_CONTROL = 0x7;





  /* set device-specific bit for timer in Nios II ienable register */

  NIOS2_WRITE_IENABLE(0x2003);
  
  /* set IE bit in Nios II status register */

  NIOS2_WRITE_STATUS(1);

}



extern int flag;



int main(void){

    int value;


    initTimer();

    PrintString("ELEC 371 Lab 4\n");

    InitADC(0x2,0x2);
	



    while(1){
		
		
	
        value = ADConvert();
		//*LEDS = value;
        

		if(flag == 1){

			flag = 0;

			PrintString("\b");
			
			value = (value>>6);
			
		if(value ==0){
		PrintString(".");
		}
		if(value ==1){
		PrintString(":");
		}
		if(value ==2){
		PrintString("!");
		}
		if(value ==3){
		PrintString("|");
		}
		
		
			
			
			

		}

    }



    return 0;

}