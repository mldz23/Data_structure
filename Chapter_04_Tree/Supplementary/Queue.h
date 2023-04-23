#pragma once
#include <iostream>
#include "LinkTree.h"
using namespace std;

//��Ϊ�����еĽ��
typedef struct QNode {
	BiTree data;
	struct QNode* next;
}QNode;

//���б���
typedef struct LinkQueue {
	QNode* front, * rear;
}LinkQueue;

//���еĳ�ʼ������
void InitQueue(LinkQueue& Q);

//���е��пպ���
bool QueueEmpty(LinkQueue Q);

//���
bool EnQueue(LinkQueue& Q, BiTree T);

//����
bool DeQueue(LinkQueue& Q ,BiTree &T);
