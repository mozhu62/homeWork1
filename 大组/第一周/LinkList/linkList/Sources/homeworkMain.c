#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<Windows.h>
#include<ctype.h>

#include"linkListLearning.h"

bool running = true;
bool isLoop = false;
int menuNum = 0;

void MenuPrinting()
{
	char* menu[] = {
		"|-------------------------------------------------|\n",
		"|              请输入对应数字进行操作             |\n",
		"|   1.初始化链表                   2.插入节点     |\n",
		"|   3.链表查询                     4.删除节点     |\n",
		"|   5.输出链表                     6.反转链表     |\n",
		"|   7.中间链表                     8.奇偶反转     |\n",
		"|   9.判断链表是否成环            10.链表成环     |\n",
		"|  11.退出程序                                    |\n",
		"|-------------------------------------------------|\n",

	};
	int menuItems = sizeof(menu) / sizeof(menu[0]);
	for (int i = 0; i<menuItems; i++)
	{
		puts(menu[i]);
	}

}
struct Node* initialRef()//初始化链表
{
	int nodeNum = 0;
	system("cls");
	MenuPrinting();
	printf("请输入节点个数(不超过20):");
	
	while (true)
	{	
		scanf("%d", &nodeNum);
		if (nodeNum == 0)
		{
			system("cls");
			break;
		}
		if (0 < nodeNum && nodeNum < 21)
		{
			struct Node* head_node = createList(nodeNum);
			struct Node* currentptr = head_node;
			printf("请输入节点数据:\n");
			for (int i = 1; i <= nodeNum; i++) {
				printf("节点%d:", i);
				char tempInput[100];
				scanf("%99s", tempInput);
				currentptr->data = (char*)malloc(strlen(tempInput) + 1); // 加1是为了容纳字符串的结束字符'\0'
				strcpy(currentptr->data, tempInput);
				currentptr = currentptr->next_node;
			}
			printf("链表初始化完毕\n");
			puts("当前链表状态:");
			printList(head_node);
			getchar();
			getchar();
			system("cls");
			return head_node;
			
		}
		else
		{
			printf("输入不规范!\n请输入1到20的数:");
		}
	}
	return NULL;

}

void NodeInsert(struct Node** target)
{
	int position = 0;
	char *data = (char*)malloc(sizeof(char[100]));

	puts("请输入插入的位置(第几个节点后),若输入超过当前长度则在链表末尾添加节点,若为0则在开头添加节点");
	scanf("%d", &position);
	puts("请输入插入节点的数据");
	scanf("%99s", data);
	insertNode(target, position, data);
	system("cls");
}

void NodeSearch(struct Node* target)
{
	char target_thing[100];
	puts("请输入查询数据:");
	scanf("%99s", target_thing);
	refSearch(target, target_thing);
	Sleep(1000);
	system("cls");
}

void NodeDelete(struct Node** target)
{
	int position = 0;
	system("cls");
	MenuPrinting();
	printf("请输入想要删除的节点位置:");
	scanf("%d", &position);
	delete_node_position(target, position);
	printf("\n节点%d成功删除\n按下任意键继续...", position);
	getchar();
	getchar();
	system("cls");
}

void outList(struct Node* target)
{
	if (target == NULL)
	{
		puts("链表未初始化或初始化失败,请先初始化链表");
		Sleep(1000);
		system("cls");
		return;
	}
	system("cls");
	MenuPrinting();
	puts("当前链表为:");
	printList(target);
	getchar();
	getchar();
	system("cls");
}


struct Node* ListReverse(struct Node* head)
{
	if (NULL == head || NULL == head->next_node) 
	{
		return head;
	}
	struct Node* new_head = ListReverse(head->next_node);
	head->next_node->next_node = head;
	head->next_node = NULL;
	return new_head;
}

void MidNode(struct Node* target)
{
	struct Node* slowptr = target;
	struct Node* fastptr = target;
	while (fastptr != NULL && fastptr->next_node != NULL)
	{
		slowptr = slowptr->next_node;
		fastptr = fastptr->next_node->next_node;
	}
	printf("中间节点数据是:%s\n按任意键继续...", slowptr->data);
	getchar();
	getchar();
	system("cls");
}

void CheckLoop(struct Node* target)
{
	struct Node* slow = target;
	struct Node* fast = target;
	while (fast != NULL&&fast->next_node!=NULL)
	{
		slow = slow->next_node;
		fast = fast->next_node->next_node;
		if (slow == fast)
		{
			puts("链表已成环");
			Sleep(1000);
			system("cls");
			return;
		}
	}
	puts("链表未成环");
	Sleep(1000);
	system("cls");


}

void ListLoop(struct Node** target)
{
	if (*target == NULL)
	{
		puts("链表成环失败");
		Sleep(1000);
		system("cls");
		return;
	}
	struct Node* tail = *target;
	while (tail->next_node != NULL)
	{
		tail = tail->next_node;
	}
	tail->next_node = *target;
	isLoop = true;
	puts("链表已成环");
	Sleep(1000);
	system("cls");
}


int main(int argc,char *argv)
{
	struct Node* mainList = NULL;
	while (running)
	{
		
		MenuPrinting();
		printf("请输入对应数字(1-12):"),
		scanf("%d",&menuNum);
		if (0 < menuNum && menuNum < 12)
		{
			switch (menuNum)
			{
			case 1:
				if (isLoop) { puts("链表已成环"); Sleep(1000); system("cls"); break; }
				mainList = initialRef();
				break;
			case 2:
				if (isLoop) { puts("链表已成环"); Sleep(1000); system("cls"); break; }
				NodeInsert(&mainList);
				break;
			case 3:
				if (isLoop) { puts("链表已成环"); Sleep(1000); system("cls"); break; }
				NodeSearch(mainList);
				break;
			case 4:
				if (isLoop) { puts("链表已成环"); Sleep(1000); system("cls"); break; }
				NodeDelete(&mainList);
				break;
			case 5:
				if (isLoop) { puts("链表已成环"); Sleep(1000); system("cls"); break; }
				outList(mainList);
				break;
			case 6:
				if (isLoop) { puts("链表已成环"); Sleep(1000); system("cls"); break; }
				mainList = ListReverse(mainList);
				printf("反转链表成功\n");
				Sleep(1000);
				system("cls");
				break;
			case 7:
				if (isLoop) { puts("链表已成环"); Sleep(1000); system("cls"); break; }
				MidNode(mainList);
				break;
			case 8:
				puts("施工中...");
				getchar();
				getchar();
				system("cls");
				break;
			case 9:
				CheckLoop(mainList);
				break;
			case 10:
				ListLoop(&mainList);
				break;
			case 11:
				exit(0);
				break;
			}
		}
		else
		{
			printf("输入错误!请重新输入\n");
			printf("按任意键继续...");
			getchar();
			getchar();
			system("cls");
		}
	}
	return 0;

}