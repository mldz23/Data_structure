#pragma once
#include <iostream>
using namespace std;

//定义的是二叉树的结点
//n个结点的二叉链表共有n+1个空链域,因为头结点没有父结点
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rclild;
	//struct BiTNode *parent; //取决于应用场合
}BiTNode,*BiTree;

bool InitLinkTree(BiTree &root);

bool InsertNode(BiTree &root,int element);

BiTNode Obtainlchild(BiTNode* p);   

BiTNode Obtainrchild(BiTNode* p);


