#include "Queue.h"

void InitQueue(LinkQueue& Q)
{
	//��ͷ���
	//����ͷ��㲢����ͷβָ��ͬʱָ��ͷ���
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
	Q.front->next = NULL;

	//����ͷ���
	//Q.front = Q.rear = NULL;
}

bool QueueEmpty(LinkQueue Q)
{
	//��ͷ���
	return (Q.front == Q.rear);

	//����ͷ���
	//return (Q.front == NULL);
}


bool EnQueue(LinkQueue& Q,BiTree T)
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (p == NULL)
		return false;
	p->data = T;
	p->next = NULL;

	//������ͷ���ʱ
	/*if (Q.front = NULL)
	{
		Q.front = p;
		Q.rear = p;
		return true;
	}*/

	Q.rear->next = p;
	//p��Ϊ�µı�βָ��
	Q.rear = p;
	return true;
}


bool DeQueue(LinkQueue& Q ,BiTree &T)
{
	if (Q.front == Q.rear)
		return false;

	//����ͷ���
	//if(Q.front == NULL)
	//	return false //�ն�
	//QNode* p = Q.front;
	//element = p->data;
	//Q.front = p->next;
	//if (p == Q.rear) //����˴������һ�γ���
	//{
	//	Q.front = NULL;
	//	Q.rear = NULL;
	//}
	//free(p);
	//return true;

	QNode* p = Q.front->next;
	T = p->data;
	Q.front->next = p->next;
	//˵���ͷ�p֮��Ϊ�ն���
	if (p == Q.rear)
		Q.rear = Q.front;
	free(p);
	return true;
}