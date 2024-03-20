#pragma once
/*************************************
	��һ����ҵ,��������Ĳ�����������
 *************************************/

struct Node
{
	const char* data;
	struct Node* next_node;
};

struct twoNode//˫������
{
	const char* data;
	struct twoNode* tail_ptr;
	struct twoNode* head_ptr;
};


//����һ���ڵ�
struct Node* createNode(const char* nextData);

//��������
struct Node* createList(int nodeNum);

//����ĩβ����½ڵ�
//void appendNode(struct Node** head_ref, const char* new_data);

//����ͷ���м�����½ڵ�
void insertNode(struct Node** head_ref, int insertPosition, const char* value);

//�����ѯ
struct Node* refSearch(struct Node* head_ref, const char* searchingThing);

//��ӡ����
void printList(struct Node* head);


//����ֵ��ѯ��ɾ���׸��ڵ�
void delete_node_value(struct Node** head_ptr, const char* target);

//����λ��ɾ���ڵ�
void delete_node_position(struct Node** head_ptr, int position);