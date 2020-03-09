/*
 * sleep.h
 *
 * Created: 2020-03-09 10:49:03 AM
 *  Author: EbrahimOseif
 */ 


#ifndef SLEEP_H_
#define SLEEP_H_


#define		IDLE_MODE						0 
#define		ADC_NOISE_REDUC_MODE			1 
#define		POWER_DOWN_MODE					2 
#define		POWER_SAVE_MODE					3 
#define		STANDBY_MODE					4 
#define		EXT_STANDBY_MODE				5 



#define		IDLE_MASK						0X8F
#define		ADC_NOISE_REDUC_MASK			0X9F
#define		POWER_DOWN_MASK					0XAF
#define		POWER_SAVE_MASK					0XBF
#define		STANDBY_MASK					0XEF
#define		EXT_STANDBY_MASK				0XFF

#define     ENABLE_SLEEP_MASK				0x80




/**
* @brief: CPU_Sleep provides six modes
* 	  IDLE, ADC_NOISE_REDUC, POWER_DOWN, POWER_SAVE, STANDBY, EXT_STANDBY
* @param: sleep_mode defines sleep modes
* Input : uint8_t
* Output: None
* @return: void
*/
void set_sleep_mode(uint8_t sleep_mode);

void Sleep_enable(void);

void Sleep_disable(void);

#endif /* SLEEP_H_ */