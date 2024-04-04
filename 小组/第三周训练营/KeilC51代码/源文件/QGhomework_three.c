#include<reg51.h>
#include<intrins.h>

void Timer0Init()
{
	TR0 = 1;
	TMOD = 0X01;
	TH0 = 0XDC;
	TL0 = 0XD4;//10ms
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



void main()
{
	P2 = 0XFF;
	Timer0Init();
	P2 = 0XFE;
	PinTime(1000);
	while(1)
	{
		P2 = _crol_(P2,1);
		PinTime(1000);	
	}	
}