#include "Threaded_Binary_Tree.h"

//全局变量pre，指向当前访问节点的前驱
ThreadNode* pre = NULL;

void Visit(ThreadNode* q)
{
	//若左子树为空，建立前驱
	if (q->lchild == NULL)
	{
		q->lchild = pre;
		q->ltag = 1;
	}

	if (pre != NULL && pre->rchild == NULL)
	{
		//建立前驱结点的后序线索
		pre->rchild = q;
		pre->rtag = 1;
	}
	//在结束之前访问当前结点
	pre = q;
}



//中序线索化
void InThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T->lchild);
		Visit(T);
		InThread(T->rchild);
	}
}



void CreatInThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		InThread(T);
		if (pre->rchild == NULL)
		{
			pre->rtag = 1;
		}
	}
}

//先序线索化
void PreThread(ThreadTree T)
{
	if (T != NULL)
	{
		Visit(T);
		if(T->ltag != 1)
			PreThread(T->lchild);
		PreThread(T->rchild);
	}
}



void CreatPreThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		PreThread(T);
		if (pre->rchild == NULL)
		{
			pre->rtag = 1;
		}
	}
}



//后序线索化
void PostThread(ThreadTree T)
{
	if (T != NULL)
	{
		PostThread(T->lchild);
		PostThread(T->rchild);
		Visit(T);
	}
}

void CreatPostThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		PostThread(T);
		if (pre->rchild == NULL)
		{
			pre->rtag = 1;
		}
	}
}