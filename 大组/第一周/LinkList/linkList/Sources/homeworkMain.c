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
		"|              �������Ӧ���ֽ��в���             |\n",
		"|   1.��ʼ������                   2.����ڵ�     |\n",
		"|   3.�����ѯ                     4.ɾ���ڵ�     |\n",
		"|   5.�������                     6.��ת����     |\n",
		"|   7.�м�����                     8.��ż��ת     |\n",
		"|   9.�ж������Ƿ�ɻ�            10.����ɻ�     |\n",
		"|  11.�˳�����                                    |\n",
		"|-------------------------------------------------|\n",

	};
	int menuItems = sizeof(menu) / sizeof(menu[0]);
	for (int i = 0; i<menuItems; i++)
	{
		puts(menu[i]);
	}

}
struct Node* initialRef()//��ʼ������
{
	int nodeNum = 0;
	system("cls");
	MenuPrinting();
	printf("������ڵ����(������20):");
	
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
			printf("������ڵ�����:\n");
			for (int i = 1; i <= nodeNum; i++) {
				printf("�ڵ�%d:", i);
				char tempInput[100];
				scanf("%99s", tempInput);
				currentptr->data = (char*)malloc(strlen(tempInput) + 1); // ��1��Ϊ�������ַ����Ľ����ַ�'\0'
				strcpy(currentptr->data, tempInput);
				currentptr = currentptr->next_node;
			}
			printf("�����ʼ�����\n");
			puts("��ǰ����״̬:");
			printList(head_node);
			getchar();
			getchar();
			system("cls");
			return head_node;
			
		}
		else
		{
			printf("���벻�淶!\n������1��20����:");
		}
	}
	return NULL;

}

void NodeInsert(struct Node** target)
{
	int position = 0;
	char *data = (char*)malloc(sizeof(char[100]));

	puts("����������λ��(�ڼ����ڵ��),�����볬����ǰ������������ĩβ��ӽڵ�,��Ϊ0���ڿ�ͷ��ӽڵ�");
	scanf("%d", &position);
	puts("���������ڵ������");
	scanf("%99s", data);
	insertNode(target, position, data);
	system("cls");
}

void NodeSearch(struct Node* target)
{
	char target_thing[100];
	puts("�������ѯ����:");
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
	printf("��������Ҫɾ���Ľڵ�λ��:");
	scanf("%d", &position);
	delete_node_position(target, position);
	printf("\n�ڵ�%d�ɹ�ɾ��\n�������������...", position);
	getchar();
	getchar();
	system("cls");
}

void outList(struct Node* target)
{
	if (target == NULL)
	{
		puts("����δ��ʼ�����ʼ��ʧ��,���ȳ�ʼ������");
		Sleep(1000);
		system("cls");
		return;
	}
	system("cls");
	MenuPrinting();
	puts("��ǰ����Ϊ:");
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
	printf("�м�ڵ�������:%s\n�����������...", slowptr->data);
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
			puts("�����ѳɻ�");
			Sleep(1000);
			system("cls");
			return;
		}
	}
	puts("����δ�ɻ�");
	Sleep(1000);
	system("cls");


}

void ListLoop(struct Node** target)
{
	if (*target == NULL)
	{
		puts("����ɻ�ʧ��");
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
	puts("�����ѳɻ�");
	Sleep(1000);
	system("cls");
}


int main(int argc,char *argv)
{
	struct Node* mainList = NULL;
	while (running)
	{
		
		MenuPrinting();
		printf("�������Ӧ����(1-12):"),
		scanf("%d",&menuNum);
		if (0 < menuNum && menuNum < 12)
		{
			switch (menuNum)
			{
			case 1:
				if (isLoop) { puts("�����ѳɻ�"); Sleep(1000); system("cls"); break; }
				mainList = initialRef();
				break;
			case 2:
				if (isLoop) { puts("�����ѳɻ�"); Sleep(1000); system("cls"); break; }
				NodeInsert(&mainList);
				break;
			case 3:
				if (isLoop) { puts("�����ѳɻ�"); Sleep(1000); system("cls"); break; }
				NodeSearch(mainList);
				break;
			case 4:
				if (isLoop) { puts("�����ѳɻ�"); Sleep(1000); system("cls"); break; }
				NodeDelete(&mainList);
				break;
			case 5:
				if (isLoop) { puts("�����ѳɻ�"); Sleep(1000); system("cls"); break; }
				outList(mainList);
				break;
			case 6:
				if (isLoop) { puts("�����ѳɻ�"); Sleep(1000); system("cls"); break; }
				mainList = ListReverse(mainList);
				printf("��ת����ɹ�\n");
				Sleep(1000);
				system("cls");
				break;
			case 7:
				if (isLoop) { puts("�����ѳɻ�"); Sleep(1000); system("cls"); break; }
				MidNode(mainList);
				break;
			case 8:
				puts("ʩ����...");
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
			printf("�������!����������\n");
			printf("�����������...");
			getchar();
			getchar();
			system("cls");
		}
	}
	return 0;

}