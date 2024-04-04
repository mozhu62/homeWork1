/*使用的是清翔STC89C52*/
#include<reg52.h>
#include<stdio.h>

#include"homework51first.h"

unsigned char zifuchuan[]="helloword\n";			//待显示字符。
volatile unsigned char sending;

unsigned char LED[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//LED码表
unsigned char code weitable[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//数码管各位的码表
unsigned char code duantable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
//0-F的码表
void Timer0Init()
{
	TR0 = 1;
	TMOD |= 0X01;
	TH0 = 0XDC;
	TL0 = 0XD4;//10ms
}		   

void UARTInit()//串口初始化
{
	EA = 1;
	ES = 1;//串口中断
	REN = 1;//串口允许接收
	SM0 = 0;  SM1 = 1;//模式设置为8位波特率
	TR1 = 1;
	TMOD |= 0X20;//定时器1,模式2
	TH1 = 0XFD;
	TL1 = 0XFD;//设置波特率9600
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

void send(unsigned char d)		  //发送一个字节的数据，形参d即为待发送数据。
{
 	SBUF=d; //将数据写入到串口缓冲
 	sending=1;	 //设置发送标志
 	while(sending); //等待发送完毕
}

void sendc(unsigned char * pd)
{
 	while((*pd)!='\0') //发送字符串，直到遇到0才结束
 	{
  		send(*pd); //发送一个字符
  		pd++;  //移动到下一个字符
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

void uart(void) interrupt 4		 //串口发送中断
{
 	if(RI)    //收到数据
 	{
  		RI=0;   //清中断请求
 	}
 	else      //发送完一字节数据
 	{
  		TI=0;
  		sending=0;
 	}
}



