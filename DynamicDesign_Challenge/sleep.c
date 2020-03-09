/*
 * sleep.h
 *
 * Created: 2020-03-09 10:49:03 AM
 *  Author: EbrahimOseif
 */ 


#include "registers.h"
#include "sleep.h"


void set_sleep_mode(uint8_t sleep_mode)
{
	
	/* 	  Note: STANDBY and EXT_STANDBY sleep modes are only available with
	 	  	external crystal/resonator fuse selection */
	
  switch (sleep_mode){
	  
    case (IDLE_MODE):
  
      MCUCR |= IDLE_MASK;
      break;
	  
    case (ADC_NOISE_REDUC_MODE):
      
      MCUCR |= ADC_NOISE_REDUC_MASK;
      break;
	  
    case (POWER_DOWN_MODE):
    
      MCUCR |= POWER_DOWN_MASK;
      break;
		 
    case (POWER_SAVE_MODE):

      MCUCR |= POWER_SAVE_MASK;
	  break;
	  
    case (STANDBY_MODE):

      MCUCR |= STANDBY_MASK;
      break;

    case (EXT_STANDBY_MODE):

      MCUCR |= EXT_STANDBY_MASK;
      break;
	  
    default:
				break;
  }
  
}

void Sleep_enable(void){
	
	/* set SE BIT */
	PORTA_DIR = 0XFF;
	PORTA_DATA ^= 0XFF;
	
	MCUCR |=  ENABLE_SLEEP_MASK;
	 asm("SLEEP");	
}

void Sleep_disable(void){
	
	/* CLEAR SE BIT */
	MCUCR &= ~ ENABLE_SLEEP_MASK;
	
}
