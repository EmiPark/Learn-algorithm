#pragma once
#ifndef MIN_HEAP
#define MIN_HEAP
#include <stdio.h>
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

int DeleteMin(MinHeapNode*&E)
{
	MinHeapNode* tmp = nullptr;
	tmp = fq;
	// w = fq->weight ;  
	E = fq;
	if (E == NULL)
		return 0;
	head->next = fq->next; /*一定不能丢了链表头*/
	fq = fq->next;
	// free(tmp) ;  
	return 0;
}

int Insert(MinHeapNode* hn)
{
	if (head->next == NULL)
	{
		head->next = hn; //将元素放入链表中  
		fq = lq = head->next; //一定要使元素放到链中  
	}
	else
	{
		MinHeapNode *tmp = NULL;
		tmp = fq;
		if (tmp->cc > hn->cc)
		{
			hn->next = tmp;
			head->next = hn;
			fq = head->next; /*链表只有一个元素的情况*/
		}
		else
		{
			for (; tmp != NULL;)
			{
				if (tmp->next != NULL && tmp->cc > hn->cc)
				{
					hn->next = tmp->next;
					tmp->next = hn;
					break;
				}
				tmp = tmp->next;
			}
		}
		if (tmp == NULL)
		{
			lq->next = hn;
			lq = lq->next;
		}
	}
	return 0;
}
#endif // !MIN_HEAP

