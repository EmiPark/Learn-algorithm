#pragma once
#ifndef MIN_HEAP
#define MIN_HEAP
#include <stdio.h>
struct MinHeapNode
{
	int lcost; //�������õ��½�  
	int cc; //��ǰ����  
	int rcost; //x[s:n-1]�ж�����С���߷��ú�  
	int s; //���ڵ㵽��ǰ�ڵ��·��Ϊx[0:s]  
	int *x; //��Ҫ��һ�������Ķ�����//x[s+1:n-1]  
	struct MinHeapNode *next;
};
MinHeapNode* head = 0; /*��ͷ*/
MinHeapNode* lq = 0; /*�ѵ�һ��Ԫ��*/
MinHeapNode* fq = 0; /*�����һ��Ԫ��*/

int DeleteMin(MinHeapNode*&E)
{
	MinHeapNode* tmp = nullptr;
	tmp = fq;
	// w = fq->weight ;  
	E = fq;
	if (E == NULL)
		return 0;
	head->next = fq->next; /*һ�����ܶ�������ͷ*/
	fq = fq->next;
	// free(tmp) ;  
	return 0;
}

int Insert(MinHeapNode* hn)
{
	if (head->next == NULL)
	{
		head->next = hn; //��Ԫ�ط���������  
		fq = lq = head->next; //һ��ҪʹԪ�طŵ�����  
	}
	else
	{
		MinHeapNode *tmp = NULL;
		tmp = fq;
		if (tmp->cc > hn->cc)
		{
			hn->next = tmp;
			head->next = hn;
			fq = head->next; /*����ֻ��һ��Ԫ�ص����*/
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

