/*ʹ�õ�������STC89C52*/
#include<reg52.h>
#include<stdio.h>

#include"homework51first.h"

unsigned char zifuchuan[]="helloword\n";			//����ʾ�ַ���
volatile unsigned char sending;

unsigned char LED[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//LED���
unsigned char code weitable[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//����ܸ�λ�����
unsigned char code duantable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
//0-F�����
void Timer0Init()
{
	TR0 = 1;
	TMOD |= 0X01;
	TH0 = 0XDC;
	TL0 = 0XD4;//10ms
}		   

void UARTInit()//���ڳ�ʼ��
{
	EA = 1;
	ES = 1;//�����ж�
	REN = 1;//�����������
	SM0 = 0;  SM1 = 1;//ģʽ����Ϊ8λ������
	TR1 = 1;
	TMOD |= 0X20;//��ʱ��1,ģʽ2
	TH1 = 0XFD;
	TL1 = 0XFD;//���ò�����9600
}


void PinTime(unsigned int ms)
{
	unsigned int msec = 0;
	Timer0Init();
	while(msec < ms/10)
	{
		if(TF0==1)
		{
			TF0 = 0;
			TH0 = 0XDC;
			TL0 = 0XD4;//10ms
			msec++;
		}	
	}
}

void send(unsigned char d)		  //����һ���ֽڵ����ݣ��β�d��Ϊ���������ݡ�
{
 	SBUF=d; //������д�뵽���ڻ���
 	sending=1;	 //���÷��ͱ�־
 	while(sending); //�ȴ��������
}

void sendc(unsigned char * pd)
{
 	while((*pd)!='\0') //�����ַ�����ֱ������0�Ž���
 	{
  		send(*pd); //����һ���ַ�
  		pd++;  //�ƶ�����һ���ַ�
 	}
}

void main()
{
	UARTInit();
	Timer0Init();
	while(1)
	{
		sendc(zifuchuan);
		PinTime(1000);			
	}
}

void uart(void) interrupt 4		 //���ڷ����ж�
{
 	if(RI)    //�յ�����
 	{
  		RI=0;   //���ж�����
 	}
 	else      //������һ�ֽ�����
 	{
  		TI=0;
  		sending=0;
 	}
}



