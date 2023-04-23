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

	//����
	p->right = Node;
	Node->left = q;

	//���½��ĸ߶�
	p->height = height(p);
	Node->height = height(Node);

	//������ת��Ľ��
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

	//Ҫ���²���·����ÿ�����ĸ߶�
	Node->height = height(Node);

	//����ƽ������,�����ƽ������Ҫ����
	int blance_factor = GetBlanceFactor(Node);

	//LL��
	if (blance_factor > 1 && key < Node->left->key)
		return Right_Rotate(Node);
	
	//RR��
	if (blance_factor < -1 && key > Node->right->key)
		return Left_Rotate(Node);

	//LR��
	if (blance_factor > 1 && key > Node->left->key)
	{
		Node->left = Left_Rotate(Node->left);
		return Right_Rotate(Node);
	}

	//RR��
	if (blance_factor < -1 && key < Node->right->key)
	{
		Node->right = Right_Rotate(Node->right);
		return Left_Rotate(Node);
	}


	//�����ƽ���ֱ�ӷ��ؽ��
	return Node;
}