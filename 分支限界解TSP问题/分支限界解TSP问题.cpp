// ��֧�޽��TSP����.cpp : �������̨Ӧ�ó������ڵ㡣
//
//�ο����ף�http://blog.csdn.net/whzhaochao/article/details/12716417
#include "stdafx.h"
#include "MinHeap.h"
using namespace std;
#define NoEdge 10000  
int N;	//��������
int nVertex;	//ͼG�Ķ�����  
int **am; //ͼG���ڽӾ���  
//int   NoEdge;   //ͼG���ޱ߱��  
int curc; //��ǰ����  
int bestc; //��ǰ��С����  
int *bestArray;//�洢���Ž������
struct City
{
	int num;
	int x;
	int y;
};
int **ds2am(City *city, int n);
int BBTSP(int v[]);
int main()
{
	string sN, sCity;
	int temp;
	City* cityArray;
	ifstream input("CityList.txt");
	while (!input.is_open())
	{
		cout << "�ļ������ڣ����ݼ���ȡʧ�ܣ�" << endl;
		return 0;
	}
	cout << "���ݼ���ȡ�ɹ���" << endl;
	getline(input, sN);
	N = stoi(sN);
	cityArray = new City[N];
	for (size_t i = 0; i < N; i++)
	{
		stringstream ss(sCity);
		getline(input, sCity);
		ss << sCity;
		ss >> temp;
		cityArray[i].num = temp;
		ss >> temp;
		cityArray[i].x = temp;
		ss >> temp;
		cityArray[i].y = temp;
	}
	for (size_t i = 0; i < N; i++)
		cout << cityArray[i].num << " " << cityArray[i].x << " " << cityArray[i].y << endl;
	nVertex = N;
	int *v = new int[nVertex];
	for (int i = 0; i < nVertex; i++)
		v[i] = 0;
	am = new int*[nVertex];
	for (size_t i = 0; i < nVertex; i++)
		am[i] = new int[nVertex];
	am = ds2am(cityArray, nVertex);
	bestc = BBTSP(v);
	system("pause");
    return 0;
}

int BBTSP(int v[])
{
	head = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	//head = new MinHeapNode[nVertex];
	head->cc = 0;
	head->x = 0;
	head->lcost = 0;
	head->next = nullptr;
	head->rcost = 0;
	head->s = 0;
	int * MinOut = new int[nVertex + 1];	//������С���߷���
	int MinSum = 0;	//��С���߷����ܺ�
	for (size_t i = 0; i < nVertex; i++)
	{
		int Min = NoEdge;	//��ǰ��Сֵ
		for (size_t j = 0; j < nVertex; j++)
		{
			if (am[i][j] != NoEdge && (am[i][j] < Min || Min == NoEdge))
				Min = am[i][j];
		}
		if (Min == NoEdge)
			return NoEdge;
		MinOut[i] = Min;
		MinSum += Min;
	}
	MinHeapNode *E = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	E->x = new int[nVertex];
	for (size_t i = 0; i < nVertex; i++)
		E->x[i] = i + 1;
	E->s = 0;
	E->cc = 0;
	E->rcost = MinSum;
	E->next = 0; 
	int bestc = NoEdge;
	while (E->s < nVertex - 1)	//��Ҷ�ӽ��
	{
		cout << "ִ��1" << endl;
		if (E->s == nVertex - 2) //��ǰ��չ�����Ҷ�ӽ��ĸ����	
		{
			cout << "ִ��2" << endl;
			if (am[E->x[nVertex - 2]][E->x[nVertex - 1]] != NoEdge&&am[E->x[nVertex - 1]][1] != NoEdge&&//��ǰ��չ����Ҷ�ӽ���бߴ����ҵ�ǰҶ�ӽ���л�·
				E->cc + am[E->x[nVertex - 2]][E->x[nVertex - 1]] + am[E->x[nVertex - 1]][1] < bestc || bestc == NoEdge)//�ý����Ӧ����С����С����
			{
				cout << "ִ��3" << endl;
				bestc = E->cc + am[E->x[nVertex - 2]][E->x[nVertex - 1]] + am[E->x[nVertex - 1]][1];
				E->cc = bestc;
				E->lcost = bestc;
				E->s++;
				E->next = nullptr;
				Insert(E);
			}
			else
				free(E->x);
		}
		else  //������ǰ��չ���Ķ��ӽ��
		{
			cout << "ִ��4" << endl;
			for (size_t i = E->s+1; i < nVertex; i++)
			{
				if (am[E->x[E->s]][E->x[i]] != NoEdge)	//��ǰ��չ��㵽��������бߴ���
				{
					int cc = E->cc + am[E->x[E->s]][E->x[i]];	//���Ͻ��i��ǰ���·��
					int rcost = E->rcost - MinOut[E->x[E->s]];		//ʣ����ĺ�
					int b = cc + rcost;	//�½�
					if (b < bestc || bestc == NoEdge);//�������ܺ����Ž⣬��������С��
					{
						MinHeapNode *F = (MinHeapNode*)malloc(sizeof(MinHeapNode));
						F->x = new int[nVertex];
						for (size_t j = 0; j < nVertex; j++)
							F->x[j] = E->x[j];
						F->x[E->s + 1] = E->x[i];
						F->x[i] = E->x[E->s + 1];//��ӵ�ǰ·��
						F->cc = cc; //���µ�ǰ·������
						F->s = E->s + 1; //���µ�ǰ�ڵ�
						F->lcost = b; //���µ�ǰ�½�
						F->rcost = rcost;
						F->next = NULL;
						Insert(F);  //��������ж��ӽ����뵽�������ȶ�����
					}
				}
				free(E->x);
			}
		}
		DeleteMin(E);
		if (E == nullptr)
			break;
	}
	if (bestc == NoEdge)
		return NoEdge;
	bestArray = new int[nVertex];
	for (size_t i = 0; i < nVertex; i++)
		bestArray[i] = E->x[i];
	while (true)
	{
		free(E->x);
		DeleteMin(E);
		if (E == nullptr) break;
	}
	return bestc;
}
double distance(City a, City b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
int **ds2am(City *city, int n)
{
	int **am = new int *[n];
	for (size_t i = 0; i < n; i++)
		am[i] = new int[n];
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			am[i][j] = static_cast<int>(distance(city[i], city[j]));
	return am;
}
