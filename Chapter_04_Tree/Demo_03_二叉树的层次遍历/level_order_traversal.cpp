#include "level_order_traversal.h"
#include "recursion_traversal.h"

void Level_Order(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);
	//��ʱʹ�õ���,�����鿴�����еĽ��
	BiTree p;
	EnQueue(Q, T);
	while (!QueueEmpty(Q))
	{
		DeQueue(Q,p);
		Visit(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rclild != NULL)
			EnQueue(Q, p->rclild);
	}
}