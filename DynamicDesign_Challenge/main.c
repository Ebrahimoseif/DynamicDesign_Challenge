/*
 * DynamicDesign_Challenge.c
 *
 * Created: 2020-02-24 11:20:22 AM
 * Author : EbrahimOseif
 */ 

#include "tmu.h"
#include "Timer.h"
#include "DIO.h"
//#include "interrupt.h"


void led0_toggle(void){
	
	/*PORTA_DATA ^= HIGH;
	//_delay_ms(1000);*/
	
	DIO_Toggle(GPIOB, BIT5);
}
void led1_toggle(void){
	
	/*PORTC_DATA ^= HIGH;
	//_delay_ms(1000);
	*/
		DIO_Toggle(GPIOB, BIT6);

}
void led2_toggle(void){
	
	/*PORTD_DATA ^= HIGH;
	//_delay_ms(1000);
	*/
		DIO_Toggle(GPIOB, BIT7);

}


int main(void)
{
	
	DIO_Cfg_s Leds ={
		GPIOB,
		BIT5 |BIT6 |BIT7,
		OUTPUT
	};
	
	DIO_init(&Leds);
	
	TMU_Init();
	
	TMU_Start(led0_toggle, 1000, PERIODIC);
	TMU_Start(led1_toggle, 500, ONE_SHOT);
	TMU_Start(led2_toggle, 2000, PERIODIC);

	sei();

    /* Replace with your application code */
    while (1) 
    {
				//fun();
		   TMU_Dispatcher();
    }
	
	
	
	      /* testing timers
	   struct Timer_cfg_s st_Timer_cfg={
       	TIMER_CH0,
       	TIMER_MODE,
       	TIMER_INTERRUPT_MODE,
       	TIMER_PRESCALER_1024
       };
	Timer_Init(&st_Timer_cfg);
	Timer_Start(0,100);
	*/
	/*PORTA_DIR = 0xff;
	PORTC_DIR = 0xff;
	PORTD_DIR = 0xff;*/
	
	
	
}




