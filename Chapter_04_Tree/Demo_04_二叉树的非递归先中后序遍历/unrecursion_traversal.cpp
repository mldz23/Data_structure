#include "unrecursion_traversal.h"

//�ȸ�����
void PreunrecursionOrder(BiTree T)
{
	LinkStack p;
	InitStack(p);
	Push(p, T);

	while (!IsEmpty(p))
	{
		BiTree q = GetTop(p);
		Pop(p);

		if (q->rclild != NULL)
			Push(p, q->rclild);
		if (q->lchild != NULL)
			Push(p, q->lchild);
	}
}

//�и�����
void InunrecursionOrder(BiTree T)
{
	LinkStack p;
	InitStack(p);
	//��ǰ�ڵ��ָ��
	BiTree current_Node = T;
	//��Ϊ��ʼջΪ�գ�������Ҫ��һ��current_Node���ж�����
	while (current_Node || !IsEmpty(p))
	{
		//��ǰ�ڵ㲻Ϊ��
		while (current_Node)
		{
			Push(p, current_Node);
			current_Node = current_Node->lchild;
		}
		//���ⲽ˵����ǰ�ڵ��Ѿ�û����������,������ջ
		Pop(p);
		//�ѵ�ǰ�Ľ����Ϊ����������
		current_Node = current_Node->rclild;
	}
}

//�������
void PostunrecursionOrder(BiTree T)
{
	LinkStack p;
	InitStack(p);

	BiTree current_Node = T;//���浱ǰ���ָ��
	BiTree visitNode = T;//������һ�����ʵĽ��

	while (current_Node || !IsEmpty(p))
	{
		//��ǰ���ǿգ�����������������ջ
		while (current_Node)
		{
			Push(p, current_Node);
			current_Node = current_Node->lchild;
		}
		//ȡջ��Ԫ��
		current_Node = GetTop(p);

		//���ջ��Ԫ������������������δ�����ʹ�
		if (current_Node->rclild != NULL && visitNode != current_Node->rclild)
		{
			current_Node = current_Node->rclild;
		}
		else
		{
			visitNode = current_Node;
			current_Node = NULL;
			Pop(p);
		}
	}

}