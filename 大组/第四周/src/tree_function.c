#include"binary_sort_tree.h"


//����ʼ��
Status BST_init(BinarySortTreePtr RootNode)
{
	RootNode->root = NULL;
	return succeed;
}
//����
Status BST_insert(BinarySortTreePtr RootNode, ElemType value)
{
	NodePtr current_node = RootNode->root;
	if (RootNode->root == NULL)
	{
		RootNode->root = (NodePtr)malloc(sizeof(Node));
		if (RootNode->root == NULL) {
			perror("���ڵ��ڴ����ʧ��");
			return failed;
		}
		RootNode->root->value = value;
		RootNode->root->left = NULL;
		RootNode->root->right = NULL;
		return succeed;
	}
	else
	{
		while (true)
		{
			if (current_node->value < value&&current_node->right!=NULL)
			{
				current_node = current_node->right;
			}
			else if (current_node->value > value&&current_node->left!=NULL)
			{
				current_node = current_node->left;
			}
			else if(current_node->value==value)
			{
				printf("�������Ѿ�����,�������");
				return failed;
			}
			else
			{
				NodePtr new_node = (NodePtr)malloc(sizeof(Node));
				if (new_node == NULL) {
					perror("�ڵ��ڴ����ʧ��");
					return failed;
				}
				new_node->value = value;
				new_node->left = NULL; new_node->right = NULL;
				if (current_node->value > value) {
					current_node->left = new_node;
				}
				else {
					current_node->right = new_node;
				}
				return succeed;
			}
			
		}
	}
}
//��ѯ
Status BST_search(BinarySortTreePtr RootNode, ElemType value)
{
	NodePtr current = RootNode->root;
	if (RootNode->root == NULL)
	{
		printf("��Ϊ��,�����ڽڵ�\n");
		return failed;
	}
	while (true)
	{
		if (current->value > value)
		{
			if (current->left != NULL)
			{
				current = current->left;
			}
			else
			{
				printf("��ֵ��Ӧ�Ľڵ㲻����\n");
				return failed;
			}
		}
		else if (current->value < value)
		{
			if (current->right != NULL)
			{
				current = current->right;
			}
			else
			{
				printf("����ֵ��Ӧ�Ľڵ㲻����\n");
				return failed;
			}
		}
		else
		{
			printf("����ֵ��Ӧ�Ľڵ����\n");
			return succeed;
		}
	}
}
//ɾ��
Status BST_delete(BinarySortTreePtr RootNode, ElemType value)
{
	NodePtr current = RootNode->root;
	NodePtr parent = NULL;
	if (RootNode->root == NULL)
	{
		printf("��Ϊ��,û�п�ɾ���ڵ�");
		return failed;
	}
	while (true)
	{
		if (value > current->value)
		{
			if (current->right != NULL)
			{
				parent = current;
				current = current->right;
			}
			else
			{
				printf("������ɾ��ֵ��Ӧ�Ľڵ�");
				return failed;
			}
		}
		else if (value < current->value)
		{
			if (current->left != NULL)
			{
				parent = current;
				current = current->left;
			}
			else
			{
				printf("������ɾ��ֵ��Ӧ�Ľڵ�");
				return failed;
			}
		}
		else
		{
			if (current->left == NULL && current->right == NULL)//Ҷ��
			{
				if (parent == NULL){
					RootNode->root = NULL;
				}
				else if (parent->left == current) {
					parent->left = NULL;
				}
				else {
					parent->right = NULL;
				}
			}
			else if (current->left == NULL || current->right == NULL)//������
			{
				NodePtr child = (current->left != NULL) ? current->left : current->right;
				if (parent == NULL){
					RootNode->root = child;
				}
				else if (current == parent->left) {
					parent->left = child;
				}
				else {
					parent->right = child;
				}
			}
			else//˫����
			{
				NodePtr successor = current->right;
				NodePtr successorParent = current;
				while (successor->left != NULL) 
				{
					successorParent = successor;
					successor = successor->left;
				}
				current->value = successor->value; 
				if (successorParent->left == successor) {
					successorParent->left = successor->right;
				}
				else {
					successorParent->right = successor->right;
				}
				current = successor; 
			}
			free(current);
			return succeed;
		}
	}
}

//��ʼ��ջ
void InitStack(LinkStack* S) 
{
	S->top = NULL;
}
//�ж�ջ�ղ���
Status IsEmpty(LinkStack S) 
{
	return (S.top == NULL) ? succeed : failed;
}
//��ջ
Status Push(LinkStack* S, NodePtr node) 
{
	LinkStackNode* newNode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (!newNode) return failed;
	newNode->TreeNode = node;
	newNode->next = S->top;
	S->top = newNode;
	return succeed;
}
//��ջ
Status Pop(LinkStack* S, NodePtr* node) 
{
	if (IsEmpty(*S)) return failed;
	LinkStackNode* tempNode = S->top;
	*node = tempNode->TreeNode;
	S->top = tempNode->next;
	free(tempNode);
	return succeed;
}
//ǰ������޵ݹ�
Status BST_preorderI(BinarySortTreePtr RootNode, void (*visit)(NodePtr)) 
{
	if (!RootNode || !RootNode->root) 
		return failed;
	LinkStack* temp_stack = (LinkStack*)malloc(sizeof(LinkStack));
	if (!temp_stack) {
		perror("������ʱ��ջʧ��");
		return failed;
	}
	InitStack(temp_stack);
	NodePtr currentNode = RootNode->root;

	while (currentNode || !IsEmpty(*temp_stack)) 
	{
		while (currentNode) 
		{
			visit(currentNode);//�����ݽ��в���,�ص�����֮��
			if (currentNode->right) 
				Push(temp_stack, currentNode->right); 
			currentNode = currentNode->left; 
		}
		if (!IsEmpty(*temp_stack)) 
			Pop(temp_stack, &currentNode); 
	}

	free(temp_stack);
	return failed;
}
//ǰ������ݹ�
Status BST_preorderR(BinarySortTreePtr RootNode, void (*visit)(NodePtr)) 
{
	if (!RootNode || !RootNode->root)  // �������
		return;
	visit(RootNode->root);  // ���ʵ�ǰ�ڵ�

	BST_preorderR(RootNode->root->left, visit);  // ����������
	BST_preorderR(RootNode->root->right, visit); // ����������
}