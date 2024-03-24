#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"LinkStack.h"

Status initLStack(LinkStack* list_stack){
	list_stack->top = NULL;
	list_stack->count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack* list_stack)
{
	if (list_stack->count == 0)
		return SUCCESS;
	return ERROR;
}
Status CpushLStack(LinkStack* list_stack,char target)
{
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	if (new_node == NULL) {
		return ERROR;
	}
	new_node->num = -1;
	new_node->data = target;
	new_node->next = list_stack->top;
	list_stack->top = new_node;
	list_stack->count++;
	return SUCCESS;
}

Status IpushLStack(LinkStack* list_stack, int target)
{
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	if (new_node == NULL) {
		return ERROR;
	}
	new_node->num = target;
	new_node->data = '\0';
	new_node->next = list_stack->top;
	list_stack->top = new_node;
	list_stack->count++;
	return SUCCESS;
}

Status CpopLStack(LinkStack* list_stack,char* target)
{
	if (list_stack->top == NULL) {
		puts("LinkStack is empty");
		return ERROR;
	}
	*target = list_stack->top->data;
	StackNode* currentptr = list_stack->top;
	list_stack->top = list_stack->top->next;
	free(currentptr);
	list_stack->count--;
	return SUCCESS;
}

/*Status IpopLStack(LinkStack* list_stack, int* target)
{
	if (list_stack->top == NULL) {
		puts("LinkStack is empty");
		return ERROR;
	}
	*target = list_stack->top->num;
	StackNode* currentptr = list_stack->top;
	list_stack->top = list_stack->top->next;
	free(currentptr);
	list_stack->count--;
	return SUCCESS;
}*/

char getTopLStack(LinkStack* list_stack)
{
	return list_stack->top->data;
}

int newStrlen(char* string)
{
	int i = 0;
	while (string[i] != '\n')
		i++;
	return i;
}

int readNumber(char* infix, int* index,int max) {
	int num = 0;
	while (isdigit(infix[*index])&&(*index)<max) {
		num = num * 10 + (infix[*index] - '0');
		(*index)++;
	}
	return num;
}

/*void PringLStack(LinkStack* list_stack)
{
	while (list_stack->top != NULL)
	{
		if (list_stack->top->num == -1)
			printf("%c", list_stack->top->data);
		else if (list_stack->top->data == '\0')
			printf("%d", list_stack->top->num);
		list_stack->top = list_stack->top->next;
	}
}*/


void PringOutList(StackNode target[],int dex)
{
	printf("后缀表达式为:");
	for (int i = 0; i < dex; i++)
	{
		if (target[i].isnum)
			printf("%d", target[i].num);
		else
			printf("%c", target[i].data);
		printf(" ");
	}
	printf("\n继续输入:");
}

Status LStackLength(LinkStack* list_stack, int* length)
{
	*length = list_stack->count;
	return SUCCESS;
}

Status clearLStack(LinkStack* list_stack)
{
	StackNode* current = list_stack->top;
	while (list_stack->top != NULL)
	{
		list_stack->top = list_stack->top->next;
		free(current);
		current = list_stack->top;
	}
	return SUCCESS;
}

Status destroyLStack(LinkStack* list_stack)//销毁栈
{
	clearLStack(list_stack);
	free(list_stack);
	return SUCCESS;
}