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



//��ջ
Status initLStack(LinkStack* list_stack);//��ʼ��ջ//
Status isEmptyLStack(LinkStack* list_stack);//�ж�ջ�Ƿ�Ϊ��//

char getTopLStack(LinkStack* list_stack);//�õ�ջ��Ԫ��//

Status clearLStack(LinkStack* list_stack);//���ջ//
Status destroyLStack(LinkStack* list_stack);//����ջ//
Status LStackLength(LinkStack* list_stack, int* length);//���ջ����//

Status CpushLStack(LinkStack* list_stack, char target);//��ջ//
Status IpushLStack(LinkStack* list_stack, int target);//��ջ//

Status CpopLStack(LinkStack* list_stack, char* target);//��ջ//

void PringOutList(StackNode target[]);//
int readNumber(char* infix, int* index, int max);//
int newStrlen(char* string);//


#endif 
