#include<reg52.h>
#include<intrins.h>



sbit flag = P3^7;
sbit beep = P2^3;	//������
sbit keys2 = P3^0;	//s2��������
sbit dula=P2^6;		//��ѡ�źŵ�����������
sbit wela=P2^7;		//λѡ�źŵ�����������

void timer0Init();//��ʱ��0��ʼ��
void int1Init();//�ⲿ�жϳ�ʼ��
void pintime(int ms);//��ʱ(0~50ms���)
