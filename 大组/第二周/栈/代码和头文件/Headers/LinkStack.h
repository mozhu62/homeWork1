#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define MAX_STRING_LENGTH 15

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	char data;
	int num;
	int isnum;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack* list_stack);//初始化栈//
Status isEmptyLStack(LinkStack* list_stack);//判断栈是否为空//

char getTopLStack(LinkStack* list_stack);//得到栈顶元素//

Status clearLStack(LinkStack* list_stack);//清空栈//
Status destroyLStack(LinkStack* list_stack);//销毁栈//
Status LStackLength(LinkStack* list_stack, int* length);//检测栈长度//

Status CpushLStack(LinkStack* list_stack, char target);//入栈//
Status IpushLStack(LinkStack* list_stack, int target);//入栈//

Status CpopLStack(LinkStack* list_stack, char* target);//出栈//

void PringOutList(StackNode target[]);//
int readNumber(char* infix, int* index, int max);//
int newStrlen(char* string);//


#endif 
