#pragma once
/*************************************
	第一周作业,单向链表的操作函数声明
 *************************************/

struct Node
{
	const char* data;
	struct Node* next_node;
};

struct twoNode//双向链表
{
	const char* data;
	struct twoNode* tail_ptr;
	struct twoNode* head_ptr;
};


//创建一个节点
struct Node* createNode(const char* nextData);

//创建链表
struct Node* createList(int nodeNum);

//链表末尾添加新节点
//void appendNode(struct Node** head_ref, const char* new_data);

//链表头或中间插入新节点
void insertNode(struct Node** head_ref, int insertPosition, const char* value);

//链表查询
struct Node* refSearch(struct Node* head_ref, const char* searchingThing);

//打印链表
void printList(struct Node* head);


//根据值查询并删除首个节点
void delete_node_value(struct Node** head_ptr, const char* target);

//根据位置删除节点
void delete_node_position(struct Node** head_ptr, int position);