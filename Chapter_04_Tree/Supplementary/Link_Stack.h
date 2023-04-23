#pragma once
#include <iostream>
#include "LinkTree.h"
using namespace std;

typedef struct SNode {
	BiTNode *data;
	SNode* next;
}SNode, * LinkStack;

bool InitStack(LinkStack& Stack);

bool IsEmpty(LinkStack Stack);

bool Push(LinkStack& Stack, BiTree T);

bool Pop(LinkStack& Stack);

bool DestoryStack(LinkStack& Stack);

BiTree GetTop(LinkStack Stack);
