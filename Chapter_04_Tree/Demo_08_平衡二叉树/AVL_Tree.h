#pragma once
#include <iostream>
using namespace std;

typedef struct Node
{
	int key;
	struct Node* left, * right;
	int height;
}BBTreeNode,*BBTree;

//��������

//1.�Ƚϴ�С
int max(int a, int b);

//2.�������ĸ߶�
int height(BBTree root);

//3.�����½��
BBTreeNode* NewNode(int key);

//4.��ȡ���ƽ������
int GetBlanceFactor(BBTreeNode* Node);

//����
BBTreeNode* Left_Rotate(BBTreeNode* Node);

//����
BBTreeNode* Right_Rotate(BBTreeNode* Node);

//����
BBTreeNode* BBT_Insert(BBTreeNode* Node, int key);
