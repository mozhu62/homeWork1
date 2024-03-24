#include<reg52.h>
#include<intrins.h>



sbit flag = P3^7;
sbit beep = P2^3;	//蜂鸣器
sbit keys2 = P3^0;	//s2独立键盘
sbit dula=P2^6;		//段选信号的锁存器控制
sbit wela=P2^7;		//位选信号的锁存器控制

void timer0Init();//定时器0初始化
void int1Init();//外部中断初始化
void pintime(int ms);//延时(0~50ms误差)
