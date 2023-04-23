#pragma once
#include <iostream>
using namespace std;

//�����������Ľ��
typedef struct ThreadNode {
	int data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode,*ThreadTree;

void Visit(ThreadNode* q);


//����������
void InThread(ThreadTree T);

void CreatInThread(ThreadTree T);



//����������
void PreThread(ThreadTree T);

void CreatPreThread(ThreadTree T);



//����������
void PostThread(ThreadTree T);

void CreatPostThread(ThreadTree T);

