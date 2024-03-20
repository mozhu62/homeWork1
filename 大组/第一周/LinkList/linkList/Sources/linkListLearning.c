/*************************************
	��һ����ҵ,��������Ĳ�����������
 *************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	const char* data;
	struct Node* next_node;
};

struct Node* createNode(const char* nextData)//���������ڵ�
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if (newnode == NULL)
	{
		return NULL;
	}
	newnode->data = nextData;
	newnode->next_node = NULL;//
	return newnode;
}

struct Node* createList(int nodeNum)
{
	struct Node* head_node = createNode("0"); // ����ͷ�ڵ�
	if (head_node == NULL)
	{
		printf("ͷ�ڵ㴴��ʧ��\n");
		return NULL;
	}
	struct Node* currentptr = head_node;
	for (int i = 1; i < nodeNum; i++)
	{
		struct Node* new_node = createNode("0");
		currentptr->next_node = new_node;
		currentptr = currentptr->next_node;
		new_node->next_node = NULL;
	}
	return head_node;


}
/*void appendNode(struct Node** head_ref, const char* new_data)//β����ӽڵ�
{
	struct Node* new_node = createNode(new_data);
	struct Node* Last = *head_ref;

	new_node->data = new_data;
	new_node->next_node = NULL;//

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	while (Last->next_node != NULL)
	{
		Last = Last->next_node;
	}

	Last->next_node = new_node;
}*/

//insertPosition��ʾ�ڵڼ����ڵ������µĽڵ�
void insertNode(struct Node** head_ref, int insertPosition, const char* value)//ͷ�����м����ڵ�
{
	struct Node* beinsert_node = createNode(value);
	if (beinsert_node == NULL)
	{
		puts("Error:����ڵ�ʧ��");
		return;
	}

	if (*head_ref == NULL || insertPosition == 0)//insertPosition == 0����Ԫ�ط�������ͷ
	{
		beinsert_node->data = value;
		beinsert_node->next_node = *head_ref;
		*head_ref = beinsert_node;
		return;
	}

	struct Node* currentptr = *head_ref;
	int count_num = 1;
	while (currentptr->next_node != NULL && count_num < insertPosition)//currentptrָ������β������һ���ڵ�
	{
		currentptr = currentptr->next_node;
		count_num++;
	}
	beinsert_node->data = value;
	beinsert_node->next_node = currentptr->next_node;
	currentptr->next_node = beinsert_node;
}

struct Node* refSearch(struct Node* head_ref, const char* searchingThing)//�����ѯ
{
	struct Node* currentptr = head_ref;
	while (currentptr != NULL)
	{
		if (strcmp(searchingThing, currentptr->data) == 0)
		{
			printf("�����д��ڸ�����");
			return currentptr;
		}
		currentptr = currentptr->next_node;
	}
	printf("�����в����ڸ�����");
	return NULL;

}

void printList(struct Node* head)//��ӡ��������
{
	struct Node* currentptr = head;
	while (currentptr != NULL)
	{
		printf("%s->", currentptr->data);
		currentptr = currentptr->next_node;
	}
	printf("NULL\n");
}

void delete_node_value(struct Node** head_ptr, const char* target)//����ֵ��ѯ��ɾ���׸��ڵ�
{
	struct Node* currentptr = *head_ptr;
	struct Node* preptr = NULL;

	if (strcmp(currentptr->data, target) == 0)
	{
		*head_ptr = currentptr->next_node;
		free(currentptr);
		return;
	}
	while (currentptr != NULL)
	{
		if (strcmp(currentptr->next_node->data, target) == 0)
		{
			preptr = currentptr;
			currentptr = currentptr->next_node;
			preptr->next_node = currentptr->next_node;
			free(currentptr);
			currentptr = NULL;
			return;
		}
		currentptr = currentptr->next_node;
	}


}

void delete_node_position(struct Node** head_ptr, int position)//����λ��ɾ���ڵ�
{
	struct Node* currentptr = *head_ptr;
	struct Node* preptr = NULL;

	if (*head_ptr == NULL || position < 1)
	{
		return;
	}

	if (position == 1)
	{
		*head_ptr = currentptr->next_node;
		free(currentptr);
		return;
	}
	int diedai = 1;
	while (currentptr != NULL && diedai < position)
	{
		preptr = currentptr;
		currentptr = currentptr->next_node;
		diedai++;
	}
	if (currentptr == NULL)
	{
		printf("�������ڸ�λ�ýڵ�");
		return;
	}
	preptr->next_node = currentptr->next_node;
	free(currentptr);

}