#pragma once
#include <iostream>
using namespace std;

//������Ƕ������Ľ��
//n�����Ķ���������n+1��������,��Ϊͷ���û�и����
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rclild;
	//struct BiTNode *parent; //ȡ����Ӧ�ó���
}BiTNode,*BiTree;

bool InitLinkTree(BiTree &root);

bool InsertNode(BiTree &root,int element);

BiTNode Obtainlchild(BiTNode* p);   

BiTNode Obtainrchild(BiTNode* p);


