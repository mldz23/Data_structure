#include "LinkTree.h"

//初始化树
bool InitLinkTree(BiTree& root)
{
	root = (BiTNode*)malloc(sizeof(BiTNode));
	if (root == NULL)
		return false;
	root->lchild = NULL;
	root->rclild = NULL;
}


//在指定结点后插入元素
bool InsertNode(BiTree &root, int element)
{
	BiTNode* TNode = (BiTNode*)malloc(sizeof(BiTNode));
	if (TNode == NULL)
		return false;
	TNode->data = element;
	TNode->lchild = NULL;
	TNode->rclild = NULL;
	root->lchild != NULL ? root->lchild = TNode : root->rclild = TNode;
	return true;
}

