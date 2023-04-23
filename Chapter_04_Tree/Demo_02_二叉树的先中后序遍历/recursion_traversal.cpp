#include "recursion_traversal.h"

void Visit(BiTree T)
{

}

void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rclild);
	}
}

void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rclild);
	}
}

void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rclild);
		Visit(T);
	}
}