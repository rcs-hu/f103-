/*@filename: RCS_Gyro.c
 *@author     ���˹�       
 *@brief:     ������(��Jy901)
 *@date: 2023-4-28
*/

#include "RCS_Gyro.h"
/*---------------ȫ�ֱ���-------------*/
static float gryo_z_angle_offset = 0;
static float gryo_x_angle = 0;
static float gryo_y_angle = 0;
static float gryo_z_angle = 0;
static float gryo_z_anglespeed = 0;
/*---------------��̬����-------------*/
static void GYRO_Interrupt(void);
/*------------------------------------*/


/**
	@name: Gyro_Init
	@brief: �����ǳ�ʼ��
**/
void Gyro_Init(void)
{
	//ʹ��USART1����
    RCS_USART_Config(GYRO_USART, GYRO_GPIO, GYRO_TX, GYRO_RX, GYRO_BAUD, GYRO_PRI);
	delay_ms(100);
} 

///**
//	@name: GYRO_Interrupt
//	@brief: �жϽ��ܺ���(ʹ��ʱӳ��ɶ�ӦUSART���жϺ���)
//**/
//void USART1_IRQHandler(void)
//{
//	static uint8_t flag = 0, sum = 0, j = 0;
//	static uint8_t receive_str[20] = {0};
//	static int counter=0;
//	uint8_t receive_char;
//	
//	if(USART_GetITStatus(GYRO_USART, USART_IT_RXNE) == SET)
//	{
//		receive_char = RCS_USART_Accept_Char(GYRO_USART);
//		if(flag == 1)
//		{
//				if(j == 9)
//				{
//					if(receive_char == sum)
//					{
//						if(receive_str[0] == 0x53)
//						{
//							gryo_x_angle = (float)((int16_t)(receive_str[2]<<8)|(int16_t)(receive_str[1])) / 32768.0f * 180.0f;
//							gryo_y_angle = (float)((int16_t)(receive_str[4]<<8)|(int16_t)(receive_str[3])) / 32768.0f * 180.0f;
//							if(receive_str[5]>0&&counter<1)
//							{
//								gryo_z_angle_offset = (float)((int16_t)(receive_str[6]<<8)|(int16_t)(receive_str[5])) / 32768.0f * 180.0f ;
//								counter++;
//							}
//							else if(counter)
//							{
//								gryo_z_angle = (float)((int16_t)(receive_str[6]<<8)|(int16_t)(receive_str[5])) / 32768.0f * 180.0f - gryo_z_angle_offset;  //����Ư
//								gryo_z_angle = gryo_z_angle>180.0f?gryo_z_angle-360.0f:gryo_z_angle;
//								gryo_z_angle = gryo_z_angle<=-180.0f?gryo_z_angle+360.0f:gryo_z_angle;
//							}
//						}
//						else if(receive_str[0] == 0x52)
//							gryo_z_anglespeed = (float)((int16_t)(receive_str[6]<<8)|(int16_t)(receive_str[5])) / 32768.0f * 2000.0f ;
//					}
//					flag = 0;
//					sum = 0;
//					j = 0;
//				}
//				else
//				{
//					receive_str[j] = receive_char;
//					sum += receive_char;
//					j++;
//				}
//		}
//		if((flag !=1) &&(receive_char == 0x55))            //�����
//		{
//			flag = 1;  
//			sum += 0x55;
//		}
//	}
//	USART_ClearITPendingBit(GYRO_USART, USART_IT_RXNE);
//}

///**
//	@name: Get_Gyro_Z
//	@brief: ��ȡƫ����
//	@return: �Ƕ�ֵ
//**/
//float Get_Gyro_Z(void)
//{
//  return gryo_z_angle;
//}
///**
//	@name: Get_Gyro_Z_AngleSpeed
//	@brief: ��ȡƫ����
//	@return: ƫ����
//**/
//float Get_Gyro_Z_AngleSpeed(void)
//{
//  return gryo_z_anglespeed;
//}
///**
//	@name: Get_Gyro_X
//	@brief: ��ȡ��ת��
//	@return: ��ת��
//**/
//float Get_Gyro_X(void)
//{
//  return gryo_x_angle;
//}

///**
//	@name: Get_Gyro_Y
//	@brief: ��ȡ������
//	@return: ������
//**/
//float Get_Gyro_Y(void)
//{
//  return gryo_y_angle;
//}