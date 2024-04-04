/*ʹ�õ�������STC89C52*/
#include<reg52.h>
#include<intrins.h>

#include"homework51first.h"

unsigned char LED[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//LED���
unsigned char code weitable[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//����ܸ�λ�����
unsigned char code duantable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
//0-F�����
void timer0Init()//��ʱ��0��ʼ��
{
	TR0 = 1;
	TMOD = 0X01;//16λ��ʱ��ģʽ
	TH0	= 0x4b;
	TL0	= 0xfd;
	//50ms;
}

void int1Init()//�ⲿ�жϳ�ʼ��
{
	EA = 1;
	EX1 = 1;
	IT1 = 1;
}		   

void allLed() interrupt 2//�ⲿ�ж�
{
	unsigned char itr = 0;
	while(itr<8)
	{
		P1 = LED[itr];
		pintime(300);
		itr++;
	}
	pintime(300);
}

void pintime(unsigned int ms)//��ʱ(0~50ms���)
{
	unsigned char mSec=0,Sec=0;
	timer0Init();
	while(mSec<(ms/50))
	{
		if(TF0 == 1)//TF���,�������50ms
		{
			TF0 = 0;
			TH0	= 0x4b;
			TL0	= 0xfd;
			mSec++;
		}
	}

}
void intrpt()
{
	flag = 0;
	flag = 1;
}
void display(unsigned char shi,unsigned char ge)
{
	unsigned int count = 0;
	while(count<200)						   
		if(count%20 == 0)
	{
			shi++;
		P0 = weitable[0];
		wela = 1;
		wela = 0;

		P0 = duantable[ge];	  
		dula = 1;
		dula = 0;
		pintime(50);

		P0 = weitable[1];
		wela = 1;
		wela = 0;

		P0 = duantable[shi];	  
		dula = 1;
		dula = 0;
		pintime(50);
		count++;	
	}
}

void main()
{
	unsigned char Sec = 0;
	display((Sec/10),(Sec%10));
	int1Init();
	pintime(1000);
	Sec++;
	intrpt();
	P1=0x00;
	beep = 0;
	pintime(1000);
	beep = 1;



}
