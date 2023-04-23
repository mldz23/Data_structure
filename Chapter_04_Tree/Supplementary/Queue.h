#pragma once
#include <iostream>
#include "LinkTree.h"
using namespace std;

//此为队列中的结点
typedef struct QNode {
	BiTree data;
	struct QNode* next;
}QNode;

//队列本身
typedef struct LinkQueue {
	QNode* front, * rear;
}LinkQueue;

//队列的初始化函数
void InitQueue(LinkQueue& Q);

//队列的判空函数
bool QueueEmpty(LinkQueue Q);

//入队
bool EnQueue(LinkQueue& Q, BiTree T);

//出队
bool DeQueue(LinkQueue& Q ,BiTree &T);
