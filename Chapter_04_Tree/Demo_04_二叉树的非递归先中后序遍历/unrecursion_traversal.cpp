#include "unrecursion_traversal.h"

//先根遍历
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

//中根遍历
void InunrecursionOrder(BiTree T)
{
	LinkStack p;
	InitStack(p);
	//当前节点的指针
	BiTree current_Node = T;
	//因为初始栈为空，所以需要加一个current_Node的判断条件
	while (current_Node || !IsEmpty(p))
	{
		//当前节点不为空
		while (current_Node)
		{
			Push(p, current_Node);
			current_Node = current_Node->lchild;
		}
		//到这步说明当前节点已经没有左子树了,把它出栈
		Pop(p);
		//把当前的结点设为它的右子树
		current_Node = current_Node->rclild;
	}
}

//后根遍历
void PostunrecursionOrder(BiTree T)
{
	LinkStack p;
	InitStack(p);

	BiTree current_Node = T;//保存当前结点指针
	BiTree visitNode = T;//保存上一个访问的结点

	while (current_Node || !IsEmpty(p))
	{
		//当前结点非空，沿着左子树方向入栈
		while (current_Node)
		{
			Push(p, current_Node);
			current_Node = current_Node->lchild;
		}
		//取栈顶元素
		current_Node = GetTop(p);

		//如果栈顶元素有右子树且右子树未被访问过
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