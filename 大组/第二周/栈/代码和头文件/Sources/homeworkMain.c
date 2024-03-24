#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#include"LinkStack.h"

bool running = true;
bool if_wrong = false;

void MenuPrinting()
{
	char* menu[] = {
		"\033[33m|-------------------------------------------------|\n",
		"|            ��׺���ʽת��׺���ʽ����           |\n",
		"|_________________________________________________|\n",
		"|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|\n",
		"|                                                 |\n",
		"|-------------------------------------------------|\033[0m\n",


	};
	int menuItems = sizeof(menu) / sizeof(menu[0]);
	for (int i = 0; i < menuItems; i++)
	{
		printf(menu[i]);
	}
	

}

void module_two(char arr[], int size)
{
	LinkStack OperateStack;
	initLStack(&OperateStack);
	StackNode OutList[50];
	initLStack(&OperateStack);
	int index = 0;
	char target = 'a';

	for (int i = 0; arr[i] != '\n'; i++)
	{
		if (47 < arr[i] && arr[i] < 58) {//������
			int tempindex = i;
			OutList[index].num = readNumber(arr,&tempindex,size);
			OutList[index].isnum = 1;
			i = tempindex - 1;
			index++;
		}
		else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')//������
		{
			if (isEmptyLStack(&OperateStack) || getTopLStack(&OperateStack) == '(') {
				CpushLStack(&OperateStack, arr[i]); continue;
			}
			if (arr[i] == '+' || arr[i] == '-') {
				while (isEmptyLStack(&OperateStack) != SUCCESS && getTopLStack(&OperateStack) != '(') {
					CpopLStack(&OperateStack, &target);
					OutList[index].data = target;
					OutList[index].isnum = 0;
					index++;
				}
				CpushLStack(&OperateStack, arr[i]);
			}
			else if (arr[i] == '*' || arr[i] == '/') {//isEmptyLStack(&OperateStack) != SUCCESS && getTopLStack(&OperateStack) != '(' &&
				while (getTopLStack(&OperateStack) == '*' || getTopLStack(&OperateStack) == '-') {
					CpopLStack(&OperateStack, &target);
					OutList[index].data = target;
					OutList[index].isnum = 0;
					index++;
				}
				CpushLStack(&OperateStack, arr[i]);
			}
		}
		else if (arr[i] == '(')//���Ŵ���
			CpushLStack(&OperateStack, arr[i]);
		else if (arr[i] == ')') {
			while (getTopLStack(&OperateStack) != '(') {
				CpopLStack(&OperateStack, &target);
				OutList[index].data = target;
				OutList[index].isnum = 0;
				index++;
			}
			CpopLStack(&OperateStack, &target);
		}
	}
	while (!isEmptyLStack(&OperateStack))
	{
		CpopLStack(&OperateStack,&target);
		OutList[index].data = target;
		OutList[index].isnum = 0;
		index++;
	}
	PringOutList(OutList,index);
	printf("\n");
}

/*void module_three(char arr[], int size)
{
	//��ʼ��ջ
	LinkStack OperateStack;
	LinkStack Link_stack;
	char target;
	initLStack(&OperateStack);
	initLStack(&Link_stack);

	//ȫ����ջ
	for (int i = 0; arr[i] != '\n'; i++)
	{
		if (47 < arr[i] && arr[i] < 58) {//������
			int tempIndex = i;
			IpushLStack(&Link_stack,readNumber(arr,&tempIndex,size));
			i = tempIndex - 1;
		}

		else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')//������
		{
			CpushLStack(&Link_stack, ' ');
			if (isEmptyLStack(&OperateStack) || getTopLStack(&OperateStack) == '(') {
				CpushLStack(&OperateStack, arr[i]); continue;
			}
			if (arr[i] == '+' || arr[i] == '-') {
				while (isEmptyLStack(&OperateStack) != SUCCESS && getTopLStack(&OperateStack) != '(') {
					CpopLStack(&OperateStack, &target);
					CpushLStack(&Link_stack, ' ');
					CpushLStack(&Link_stack, target);
				}
				CpushLStack(&OperateStack, arr[i]);
			}
			else if (arr[i] == '*' || arr[i] == '/') {
				while (isEmptyLStack(&OperateStack) != SUCCESS && getTopLStack(&OperateStack) != '(' && getTopLStack(&OperateStack) != '+' && getTopLStack(&OperateStack) != '-') {
					CpopLStack(&OperateStack, &target);
					CpushLStack(&Link_stack, ' ');
					CpushLStack(&Link_stack, target);
				}
				CpushLStack(&OperateStack, arr[i]);
			}
		}

		else if (arr[i] == '(')//���Ŵ���
			CpushLStack(&OperateStack, arr[i]);
		else if (arr[i] == ')') {
			while (getTopLStack(&OperateStack) != '(') {
				CpopLStack(&OperateStack, &target);
				CpushLStack(&Link_stack, ' ');
				CpushLStack(&Link_stack, target);
			}
			CpopLStack(&OperateStack,&target);
		}
	}
	PringLStack(&Link_stack);
}*/

bool checkInput(char arr[])
{
	int ascll = 0;
	int bracketCount = 0;//�ж�����
	if (arr[0] < 48&&arr[0]!='+'&&arr[0]!='-'&&arr[0]!='(' || arr[0]>57)
		return true;
	for (int i = 0; arr[i] != '\n'; i++){
		ascll = (int)arr[i];
		if ((ascll < 40 || ascll == 44 || ascll == 46 || ascll>57))//�ж��������
			return true;
		if (ascll == 47) {//���ź��治��Ϊ0
			if (arr[i + 1] == '0')
				return true;
		}
		if (ascll == '(') {//(ǰ�治��û�������
			if (i > 0 && (arr[i - 1] != '+' && arr[i - 1] != '-' && arr[i - 1] != '*' && arr[i - 1] != '/'))
				return true;
			bracketCount++;
		}
		if (ascll == '+' || ascll == '-' || ascll == '*' || ascll == '/')//���������������
			if (arr[i + 1] == '+' || arr[i + 1] == '-' || arr[i + 1] == '*' || arr[i + 1] == '/')
				return true;
		if (ascll == ')')
			bracketCount--;
		if (bracketCount < 0)//)��Զ���ܶ���(
			return true;
	}
	if (bracketCount != 0)
		return true;
	
	
	return false;
}

int main(void)
{
	char inputing[100];
	MenuPrinting();
	printf("\n��������ʽ:");
	while (running)
	{
		//ģ��1:�������
		int i = 0;
		char word = 0;
		while (word !='\n') {
			if((word = getchar())== ' ')//�����ո�
				continue;
			inputing[i] = word;
			i++;
		}
		if_wrong = checkInput(inputing);
		if (if_wrong) {
			system("cls"); MenuPrinting(); puts("��������,����������:"); continue;
		}

		//ģ��2:��׺��׺ת��
		module_two(inputing,newStrlen(inputing));
	}
	while (1);
}