#ifndef MOTOR_H
#define MOTOR_H

//channel: ��ܤ��P���F 1~4
void StartMotor(unsigned char channel);
void StopMotor(unsigned char channel);

//channel: ��ܤ��P���F 1~4
//speed: ���F�t�� -1~1�A0���ʡA1���t����A-1���t����
//���F����(��main.h)
//channel 1: MOTOR_A1_Pin MOTOR_A2_Pin
//channel 2: MOTOR_B1_Pin MOTOR_B2_Pin
//channel 3: MOTOR_C1_Pin MOTOR_C2_Pin
//channel 4: MOTOR_D1_Pin MOTOR_D2_Pin
void SetMotorSpeed(unsigned char channel, float speed);

//channel: 1~4��ܤ��P���F
//�^�ǭ�: �q�W��Ū����{�b��encoder pulse��
//encoder����(��main.h)
//channel 1: ENCODER_A1_Pin ENCODER_A2_Pin
//channel 2: ENCODER_B1_Pin ENCODER_B2_Pin
//channel 3: ENCODER_C1_Pin ENCODER_C2_Pin
//channel 4: ENCODER_D1_Pin ENCODER_D2_Pin
int GetMotorSpeed(unsigned char channel);

#endif
