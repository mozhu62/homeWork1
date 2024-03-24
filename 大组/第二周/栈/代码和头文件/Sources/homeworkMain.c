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
		"|            中缀表达式转后缀表达式工具           |\n",
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
		if (47 < arr[i] && arr[i] < 58) {//操作数
			int tempindex = i;
			OutList[index].num = readNumber(arr,&tempindex,size);
			OutList[index].isnum = 1;
			i = tempindex - 1;
			index++;
		}
		else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')//操作符
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
		else if (arr[i] == '(')//括号处理
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
	//初始化栈
	LinkStack OperateStack;
	LinkStack Link_stack;
	char target;
	initLStack(&OperateStack);
	initLStack(&Link_stack);

	//全部入栈
	for (int i = 0; arr[i] != '\n'; i++)
	{
		if (47 < arr[i] && arr[i] < 58) {//操作数
			int tempIndex = i;
			IpushLStack(&Link_stack,readNumber(arr,&tempIndex,size));
			i = tempIndex - 1;
		}

		else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')//操作符
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

		else if (arr[i] == '(')//括号处理
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
	int bracketCount = 0;//判断括号
	if (arr[0] < 48&&arr[0]!='+'&&arr[0]!='-'&&arr[0]!='(' || arr[0]>57)
		return true;
	for (int i = 0; arr[i] != '\n'; i++){
		ascll = (int)arr[i];
		if ((ascll < 40 || ascll == 44 || ascll == 46 || ascll>57))//判断输入符号
			return true;
		if (ascll == 47) {//除号后面不能为0
			if (arr[i + 1] == '0')
				return true;
		}
		if (ascll == '(') {//(前面不能没有运算符
			if (i > 0 && (arr[i - 1] != '+' && arr[i - 1] != '-' && arr[i - 1] != '*' && arr[i - 1] != '/'))
				return true;
			bracketCount++;
		}
		if (ascll == '+' || ascll == '-' || ascll == '*' || ascll == '/')//不允许运算符连续
			if (arr[i + 1] == '+' || arr[i + 1] == '-' || arr[i + 1] == '*' || arr[i + 1] == '/')
				return true;
		if (ascll == ')')
			bracketCount--;
		if (bracketCount < 0)//)永远不能多于(
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
	printf("\n请输入表达式:");
	while (running)
	{
		//模块1:检测输入
		int i = 0;
		char word = 0;
		while (word !='\n') {
			if((word = getchar())== ' ')//消除空格
				continue;
			inputing[i] = word;
			i++;
		}
		if_wrong = checkInput(inputing);
		if (if_wrong) {
			system("cls"); MenuPrinting(); puts("错误输入,请重新输入:"); continue;
		}

		//模块2:中缀后缀转化
		module_two(inputing,newStrlen(inputing));
	}
	while (1);
}