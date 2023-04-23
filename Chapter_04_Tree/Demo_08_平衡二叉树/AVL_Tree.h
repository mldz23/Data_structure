#pragma once
#include <iostream>
using namespace std;

typedef struct Node
{
	int key;
	struct Node* left, * right;
	int height;
}BBTreeNode,*BBTree;

//辅助函数

//1.比较大小
int max(int a, int b);

//2.计算树的高度
int height(BBTree root);

//3.定义新结点
BBTreeNode* NewNode(int key);

//4.获取结点平衡因子
int GetBlanceFactor(BBTreeNode* Node);

//左旋
BBTreeNode* Left_Rotate(BBTreeNode* Node);

//右旋
BBTreeNode* Right_Rotate(BBTreeNode* Node);

//插入
BBTreeNode* BBT_Insert(BBTreeNode* Node, int key);
