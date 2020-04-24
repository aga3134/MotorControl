#ifndef MOTOR_H
#define MOTOR_H

//channel: 選擇不同馬達 1~4
void StartMotor(unsigned char channel);
void StopMotor(unsigned char channel);

//channel: 選擇不同馬達 1~4
//speed: 馬達速度 -1~1，0不動，1全速正轉，-1全速反轉
//馬達對應(見main.h)
//channel 1: MOTOR_A1_Pin MOTOR_A2_Pin
//channel 2: MOTOR_B1_Pin MOTOR_B2_Pin
//channel 3: MOTOR_C1_Pin MOTOR_C2_Pin
//channel 4: MOTOR_D1_Pin MOTOR_D2_Pin
void SetMotorSpeed(unsigned char channel, float speed);

//channel: 1~4選擇不同馬達
//回傳值: 從上次讀取到現在的encoder pulse數
//encoder對應(見main.h)
//channel 1: ENCODER_A1_Pin ENCODER_A2_Pin
//channel 2: ENCODER_B1_Pin ENCODER_B2_Pin
//channel 3: ENCODER_C1_Pin ENCODER_C2_Pin
//channel 4: ENCODER_D1_Pin ENCODER_D2_Pin
int GetMotorSpeed(unsigned char channel);

#endif
