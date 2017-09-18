// 分支限界解TSP问题.cpp : 定义控制台应用程序的入口点。
//
//参考文献：http://blog.csdn.net/whzhaochao/article/details/12716417
#include "stdafx.h"
#include "MinHeap.h"
using namespace std;
#define NoEdge 10000  
int N;	//城市数量
int nVertex;	//图G的顶点数  
int **am; //图G的邻接矩阵  
//int   NoEdge;   //图G的无边标记  
int curc; //当前费用  
int bestc; //当前最小费用  
int *bestArray;//存储最优解的数组
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
		cout << "文件不存在，数据集读取失败！" << endl;
		return 0;
	}
	cout << "数据集读取成功！" << endl;
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
	int * MinOut = new int[nVertex + 1];	//顶点最小出边费用
	int MinSum = 0;	//最小出边费用总和
	for (size_t i = 0; i < nVertex; i++)
	{
		int Min = NoEdge;	//当前最小值
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
	while (E->s < nVertex - 1)	//非叶子结点
	{
		cout << "执行1" << endl;
		if (E->s == nVertex - 2) //当前扩展结点是叶子结点的父结点	
		{
			cout << "执行2" << endl;
			if (am[E->x[nVertex - 2]][E->x[nVertex - 1]] != NoEdge&&am[E->x[nVertex - 1]][1] != NoEdge&&//当前扩展结点和叶子结点有边存在且当前叶子结点有回路
				E->cc + am[E->x[nVertex - 2]][E->x[nVertex - 1]] + am[E->x[nVertex - 1]][1] < bestc || bestc == NoEdge)//该结点相应费用小于最小费用
			{
				cout << "执行3" << endl;
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
		else  //产生当前扩展结点的儿子结点
		{
			cout << "执行4" << endl;
			for (size_t i = E->s+1; i < nVertex; i++)
			{
				if (am[E->x[E->s]][E->x[i]] != NoEdge)	//当前扩展结点到其他结点有边存在
				{
					int cc = E->cc + am[E->x[E->s]][E->x[i]];	//加上结点i后当前结点路径
					int rcost = E->rcost - MinOut[E->x[E->s]];		//剩余结点的和
					int b = cc + rcost;	//下界
					if (b < bestc || bestc == NoEdge);//子树可能含最优解，结点插入最小堆
					{
						MinHeapNode *F = (MinHeapNode*)malloc(sizeof(MinHeapNode));
						F->x = new int[nVertex];
						for (size_t j = 0; j < nVertex; j++)
							F->x[j] = E->x[j];
						F->x[E->s + 1] = E->x[i];
						F->x[i] = E->x[E->s + 1];//添加当前路径
						F->cc = cc; //更新当前路径距离
						F->s = E->s + 1; //更新当前节点
						F->lcost = b; //更新当前下界
						F->rcost = rcost;
						F->next = NULL;
						Insert(F);  //将这个可行儿子结点插入到活结点优先队列中
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
