#include "Threaded_Binary_Tree.h"

//ȫ�ֱ���pre��ָ��ǰ���ʽڵ��ǰ��
ThreadNode* pre = NULL;

void Visit(ThreadNode* q)
{
	//��������Ϊ�գ�����ǰ��
	if (q->lchild == NULL)
	{
		q->lchild = pre;
		q->ltag = 1;
	}

	if (pre != NULL && pre->rchild == NULL)
	{
		//����ǰ�����ĺ�������
		pre->rchild = q;
		pre->rtag = 1;
	}
	//�ڽ���֮ǰ���ʵ�ǰ���
	pre = q;
}



//����������
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

//����������
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



//����������
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