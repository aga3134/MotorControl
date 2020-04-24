#include "motor.h"
#include "main.h"

void StartMotor(unsigned char channel){
	switch(channel){
		case 1:
			HAL_TIM_PWM_Start(g_HR.pTimer8,TIM_CHANNEL_1);
			g_HR.pTimer8->Instance->CCR1 = 0;
			HAL_GPIO_WritePin(MOTOR_A2_GPIO_Port,MOTOR_A2_Pin,GPIO_PIN_RESET);
			HAL_TIM_Encoder_Start(g_HR.pTimer2,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Start(g_HR.pTimer2,TIM_CHANNEL_2);
			break;
		case 2:
			HAL_TIM_PWM_Start(g_HR.pTimer8,TIM_CHANNEL_2);
			g_HR.pTimer8->Instance->CCR2 = 0;
			HAL_GPIO_WritePin(MOTOR_B2_GPIO_Port,MOTOR_B2_Pin,GPIO_PIN_RESET);
			HAL_TIM_Encoder_Start(g_HR.pTimer3,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Start(g_HR.pTimer3,TIM_CHANNEL_2);
			break;
		case 3:
			HAL_TIM_PWM_Start(g_HR.pTimer8,TIM_CHANNEL_3);
			g_HR.pTimer8->Instance->CCR3 = 0;
			HAL_GPIO_WritePin(MOTOR_C2_GPIO_Port,MOTOR_C2_Pin,GPIO_PIN_RESET);
			HAL_TIM_Encoder_Start(g_HR.pTimer4,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Start(g_HR.pTimer4,TIM_CHANNEL_2);
			break;
		case 4:
			HAL_TIM_PWM_Start(g_HR.pTimer8,TIM_CHANNEL_4);
			g_HR.pTimer8->Instance->CCR4 = 0;
			HAL_GPIO_WritePin(MOTOR_D2_GPIO_Port,MOTOR_D2_Pin,GPIO_PIN_RESET);
			HAL_TIM_Encoder_Start(g_HR.pTimer5,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Start(g_HR.pTimer5,TIM_CHANNEL_2);
			break;
	}
}

void StopMotor(unsigned char channel){
	switch(channel){
		case 1:
			HAL_TIM_PWM_Stop(g_HR.pTimer8,TIM_CHANNEL_1);
			g_HR.pTimer8->Instance->CCR1 = 0;
			HAL_GPIO_WritePin(MOTOR_A2_GPIO_Port,MOTOR_A2_Pin,GPIO_PIN_RESET);
			HAL_TIM_Encoder_Stop(g_HR.pTimer2,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Stop(g_HR.pTimer2,TIM_CHANNEL_2);
			break;
		case 2:
			HAL_TIM_PWM_Stop(g_HR.pTimer8,TIM_CHANNEL_2);
			g_HR.pTimer8->Instance->CCR2 = 0;
			HAL_GPIO_WritePin(MOTOR_B2_GPIO_Port,MOTOR_B2_Pin,GPIO_PIN_RESET);
			HAL_TIM_Encoder_Stop(g_HR.pTimer3,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Stop(g_HR.pTimer3,TIM_CHANNEL_2);
			break;
		case 3:
			HAL_TIM_PWM_Stop(g_HR.pTimer8,TIM_CHANNEL_3);
			g_HR.pTimer8->Instance->CCR3 = 0;
			HAL_GPIO_WritePin(MOTOR_C2_GPIO_Port,MOTOR_C2_Pin,GPIO_PIN_RESET);
			HAL_TIM_Encoder_Stop(g_HR.pTimer4,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Stop(g_HR.pTimer4,TIM_CHANNEL_2);
			break;
		case 4:
			HAL_TIM_PWM_Stop(g_HR.pTimer8,TIM_CHANNEL_4);
			g_HR.pTimer8->Instance->CCR4 = 0;
			HAL_GPIO_WritePin(MOTOR_D2_GPIO_Port,MOTOR_D2_Pin,GPIO_PIN_RESET);
			HAL_TIM_Encoder_Stop(g_HR.pTimer5,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Stop(g_HR.pTimer5,TIM_CHANNEL_2);
			break;
	}
}

void SetMotorSpeed(unsigned char channel, float speed){
	int pulseWidth = 0;
	int period = g_HR.pTimer8->Init.Period+1;
	GPIO_PinState backward = GPIO_PIN_RESET;
	
	if(speed > 1) speed = 1;
	else if(speed < -1) speed = -1;
	
	if(speed >= 0){	//正轉pin設pwm，反轉pin設0
		backward = GPIO_PIN_RESET;
		pulseWidth = speed*period;
	}
	else{	//正轉pin設inverse pwm，反轉pin設1
		backward = GPIO_PIN_SET;
		pulseWidth = (1+speed)*period;
	}
	
	switch(channel){
		case 1:
			HAL_GPIO_WritePin(MOTOR_A2_GPIO_Port,MOTOR_A2_Pin,backward);
			g_HR.pTimer8->Instance->CCR1 = pulseWidth;
			break;
		case 2:
			HAL_GPIO_WritePin(MOTOR_B2_GPIO_Port,MOTOR_B2_Pin,backward);
			g_HR.pTimer8->Instance->CCR2 = pulseWidth;
			break;
		case 3:
			HAL_GPIO_WritePin(MOTOR_C2_GPIO_Port,MOTOR_C2_Pin,backward);
			g_HR.pTimer8->Instance->CCR3 = pulseWidth;
			break;
		case 4:
			HAL_GPIO_WritePin(MOTOR_D2_GPIO_Port,MOTOR_D2_Pin,backward);
			g_HR.pTimer8->Instance->CCR4 = pulseWidth;
			break;
	}
}

int GetMotorSpeed(unsigned char channel){
	int counter = 0;
	//CNT先轉成short才有正負
	switch(channel){
		case 1:
			counter = (short)g_HR.pTimer2->Instance->CNT;
			g_HR.pTimer2->Instance->CNT = 0;
			break;
		case 2:
			counter = (short)g_HR.pTimer3->Instance->CNT;
			g_HR.pTimer3->Instance->CNT = 0;
			break;
		case 3:
			counter = (short)g_HR.pTimer4->Instance->CNT;
			g_HR.pTimer4->Instance->CNT = 0;
			break;
		case 4:
			counter = (short)g_HR.pTimer5->Instance->CNT;
			g_HR.pTimer5->Instance->CNT = 0;
			break;
	}
	return counter;
}
