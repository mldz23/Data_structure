#pragma once
#include <iostream>
using namespace std;

//线索二叉树的结点
typedef struct ThreadNode {
	int data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode,*ThreadTree;

void Visit(ThreadNode* q);


//中序线索化
void InThread(ThreadTree T);

void CreatInThread(ThreadTree T);



//先序线索化
void PreThread(ThreadTree T);

void CreatPreThread(ThreadTree T);



//后序线索化
void PostThread(ThreadTree T);

void CreatPostThread(ThreadTree T);

