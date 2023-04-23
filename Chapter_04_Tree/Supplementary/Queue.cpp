#include "Queue.h"

void InitQueue(LinkQueue& Q)
{
	//带头结点
	//申请头结点并且让头尾指针同时指向头结点
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
	Q.front->next = NULL;

	//不带头结点
	//Q.front = Q.rear = NULL;
}

bool QueueEmpty(LinkQueue Q)
{
	//带头结点
	return (Q.front == Q.rear);

	//不带头结点
	//return (Q.front == NULL);
}


bool EnQueue(LinkQueue& Q,BiTree T)
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (p == NULL)
		return false;
	p->data = T;
	p->next = NULL;

	//当不带头结点时
	/*if (Q.front = NULL)
	{
		Q.front = p;
		Q.rear = p;
		return true;
	}*/

	Q.rear->next = p;
	//p成为新的表尾指针
	Q.rear = p;
	return true;
}


bool DeQueue(LinkQueue& Q ,BiTree &T)
{
	if (Q.front == Q.rear)
		return false;

	//不带头结点
	//if(Q.front == NULL)
	//	return false //空队
	//QNode* p = Q.front;
	//element = p->data;
	//Q.front = p->next;
	//if (p == Q.rear) //代表此次是最后一次出列
	//{
	//	Q.front = NULL;
	//	Q.rear = NULL;
	//}
	//free(p);
	//return true;

	QNode* p = Q.front->next;
	T = p->data;
	Q.front->next = p->next;
	//说明释放p之后为空队列
	if (p == Q.rear)
		Q.rear = Q.front;
	free(p);
	return true;
}