// 测试结构体.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct MinHeapNode
{
	int lcost; //子树费用的下界  
	int cc; //当前费用  
	int rcost; //x[s:n-1]中顶点最小出边费用和  
	int s; //根节点到当前节点的路径为x[0:s]  
	int *x; //需要进一步搜索的顶点是//x[s+1:n-1]  
	struct MinHeapNode *next;
};
MinHeapNode* head = 0; /*堆头*/
MinHeapNode* lq = 0; /*堆第一个元素*/
MinHeapNode* fq = 0; /*堆最后一个元素*/
MinHeapNode *E = 0;
int main()
{
	//head = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	head = new MinHeapNode;
	head->cc = 0;
	head->x = 0;
	head->lcost = 0;
	head->next = nullptr;
	head->rcost = 0;
	head->s = 0;
	//lq = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	lq = new MinHeapNode;
	lq->cc = 2;
	lq->x = 0;
	lq->lcost = 3;
	lq->next = nullptr;
	lq->rcost = 4;
	lq->s = 0;
	head->next = lq;
	cout << head->next->cc << endl;
	//free(head);
	delete head;
	cout << lq->cc << endl;
	//MinHeapNode *E = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	E = new MinHeapNode;
	E->x = new int[5];
	for (size_t i = 0; i < 5; i++)
		E->x[i] = i + 1;
	E->s = 0;
	E->cc = 0;
	E->rcost = 3;
	E->next = 0;
	//free(E->x);
	cout << E->x[2]<< endl;
	system("pause");
    return 0;
}

