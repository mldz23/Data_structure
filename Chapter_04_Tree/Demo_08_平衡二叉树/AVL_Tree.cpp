#include "Blanced_Binary_Tree.h"

int max(int a, int b)
{
	return a > b ? a : b;
}

int height(BBTreeNode *root)
{
	if (root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

BBTreeNode* NewNode(int key)
{
	BBTreeNode* Node = new BBTreeNode;
	Node->left = NULL;
	Node->right = NULL;
	Node->key = key;
	Node->height = 0;
	return Node;
}

int GetBlanceFactor(BBTreeNode* Node)
{
	if (Node == NULL)
		return 0;
	return height(Node->left) - height(Node->right);
}

BBTreeNode* Left_Rotate(BBTreeNode* Node)
{
	BBTreeNode* p = Node->right;
	BBTreeNode* q = p->left;

	p->left = Node;
	Node->right = q;

	p->height = height(p);
	Node->height = height(Node);
}

BBTreeNode* Right_Rotate(BBTreeNode* Node)
{
	BBTreeNode* p = Node->left;
	BBTreeNode* q = p->right;

	//右旋
	p->right = Node;
	Node->left = q;

	//更新结点的高度
	p->height = height(p);
	Node->height = height(Node);

	//返回旋转后的结点
	return p;
}

BBTreeNode* BBT_Insert(BBTreeNode* Node, int key)
{
	if (Node == NULL)
		return false;
	if (key < Node->key)
		Node->left = BBT_Insert(Node->left, key);
	else if (key > Node->key)
		Node->right = BBT_Insert(Node->right, key);
	else
		return Node;

	//要更新插入路径上每棵树的高度
	Node->height = height(Node);

	//计算平衡因子,如果不平衡则需要调整
	int blance_factor = GetBlanceFactor(Node);

	//LL型
	if (blance_factor > 1 && key < Node->left->key)
		return Right_Rotate(Node);
	
	//RR型
	if (blance_factor < -1 && key > Node->right->key)
		return Left_Rotate(Node);

	//LR型
	if (blance_factor > 1 && key > Node->left->key)
	{
		Node->left = Left_Rotate(Node->left);
		return Right_Rotate(Node);
	}

	//RR型
	if (blance_factor < -1 && key < Node->right->key)
	{
		Node->right = Right_Rotate(Node->right);
		return Left_Rotate(Node);
	}


	//如果是平衡的直接返回结果
	return Node;
}