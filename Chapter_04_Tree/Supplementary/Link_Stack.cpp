#include "Link_Stack.h"

bool InitStack(LinkStack& Stack)
{
	Stack = NULL;
	return true;
}

bool IsEmpty(LinkStack Stack)
{
	return (Stack == NULL);
}

bool Push(LinkStack& Stack, BiTree T)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	if (p == NULL)
		return false;
	p->data = T;
	p->next = Stack;
	Stack = p; //p³ÉÎªĞÂµÄÕ»¶¥
	return true;
}

bool Pop(LinkStack& Stack)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	if (p == NULL)
		return false;
	p = Stack;//ÁÙÊ±´æ´¢Õ»¶¥Ö¸Õë
	if (Stack->next != NULL)
		Stack = Stack->next;
	free(p);
	return true;
}

bool DestoryStack(LinkStack& Stack)
{
	int x;
	while (Stack != NULL)
		Pop(Stack);
	return true;
}

BiTree GetTop(LinkStack Stack)
{
	return Stack->data;
}