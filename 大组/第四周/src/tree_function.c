#include"binary_sort_tree.h"


//树初始化
Status BST_init(BinarySortTreePtr RootNode)
{
	RootNode->root = NULL;
	return succeed;
}
//插入
Status BST_insert(BinarySortTreePtr RootNode, ElemType value)
{
	NodePtr current_node = RootNode->root;
	if (RootNode->root == NULL)
	{
		RootNode->root = (NodePtr)malloc(sizeof(Node));
		if (RootNode->root == NULL) {
			perror("根节点内存分配失败");
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
				printf("该数据已经存在,无需插入");
				return failed;
			}
			else
			{
				NodePtr new_node = (NodePtr)malloc(sizeof(Node));
				if (new_node == NULL) {
					perror("节点内存分配失败");
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
//查询
Status BST_search(BinarySortTreePtr RootNode, ElemType value)
{
	NodePtr current = RootNode->root;
	if (RootNode->root == NULL)
	{
		printf("树为空,不存在节点\n");
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
				printf("该值对应的节点不存在\n");
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
				printf("搜索值对应的节点不存在\n");
				return failed;
			}
		}
		else
		{
			printf("搜索值对应的节点存在\n");
			return succeed;
		}
	}
}
//删除
Status BST_delete(BinarySortTreePtr RootNode, ElemType value)
{
	NodePtr current = RootNode->root;
	NodePtr parent = NULL;
	if (RootNode->root == NULL)
	{
		printf("树为空,没有可删除节点");
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
				printf("不存在删除值对应的节点");
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
				printf("不存在删除值对应的节点");
				return failed;
			}
		}
		else
		{
			if (current->left == NULL && current->right == NULL)//叶子
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
			else if (current->left == NULL || current->right == NULL)//单孩子
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
			else//双孩子
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

//初始化栈
void InitStack(LinkStack* S) 
{
	S->top = NULL;
}
//判断栈空不空
Status IsEmpty(LinkStack S) 
{
	return (S.top == NULL) ? succeed : failed;
}
//入栈
Status Push(LinkStack* S, NodePtr node) 
{
	LinkStackNode* newNode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (!newNode) return failed;
	newNode->TreeNode = node;
	newNode->next = S->top;
	S->top = newNode;
	return succeed;
}
//出栈
Status Pop(LinkStack* S, NodePtr* node) 
{
	if (IsEmpty(*S)) return failed;
	LinkStackNode* tempNode = S->top;
	*node = tempNode->TreeNode;
	S->top = tempNode->next;
	free(tempNode);
	return succeed;
}
//前序遍历无递归
Status BST_preorderI(BinarySortTreePtr RootNode, void (*visit)(NodePtr)) 
{
	if (!RootNode || !RootNode->root) 
		return failed;
	LinkStack* temp_stack = (LinkStack*)malloc(sizeof(LinkStack));
	if (!temp_stack) {
		perror("创建临时链栈失败");
		return failed;
	}
	InitStack(temp_stack);
	NodePtr currentNode = RootNode->root;

	while (currentNode || !IsEmpty(*temp_stack)) 
	{
		while (currentNode) 
		{
			visit(currentNode);//对数据进行操作,回调函数之处
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
//前序遍历递归
Status BST_preorderR(BinarySortTreePtr RootNode, void (*visit)(NodePtr)) 
{
	if (!RootNode || !RootNode->root)  // 空树检查
		return;
	visit(RootNode->root);  // 访问当前节点

	BST_preorderR(RootNode->root->left, visit);  // 访问左子树
	BST_preorderR(RootNode->root->right, visit); // 访问右子树
}