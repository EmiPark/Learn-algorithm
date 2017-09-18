// 分支限界解旅行商问题.cpp : 定义控制台应用程序的入口点。
//参考文献：http://blog.csdn.net/qq_32400847/article/details/51813606

#include "stdafx.h"
using namespace std;
const int INF = 10000;
const int CityNum = 120;
int low, up, n, used[CityNum], graph[CityNum][CityNum];
struct City
{
	int num;
	int x;
	int y;
};
struct node
{
	bool vis[CityNum];
	int st;//路径的起点   
	int ed;//路径的终点  
	int k;//走过的点数  
	int sumv;//经过路径的距离  
	int lb;//目标函数的值  
	bool operator<(const node &p)const
	{
		return lb>p.lb;
	}
};
priority_queue<node> q;

int get_up_helper(int v, int j, int len)
{
	if (j == n) return len + graph[v][1];
	int minlen = INF, pos;
	for (int i = 1; i <= n; i++)
	{
		if (used[i] == 0 && minlen>graph[v][i])
		{
			minlen = graph[v][i];
			pos = i;
		}
	}
	used[pos] = 1;
	return get_up_helper(pos, j + 1, len + minlen);
}

//贪心取最小权值的边作为上界  
void get_up()
{
	used[1] = 1;
	up = get_up_helper(1, 1, 0);
}

//部分解的目标函数的下界  
//已经经过的路径的总长的2倍+从起点到最近未遍历城市的距离+从终点到最近未遍历城市的距离+进入/离开未遍历城市时各未遍历城市带来的最小路径成本)除以2并向上取整
int get_lb(node p)
{
	int ret = p.sumv * 2;
	int min1 = INF, min2 = INF;
	//从起点到最近未遍历城市的距离  
	for (int i = 1; i <= n; i++)
	{
		if (p.vis[i] == 0 && min1>graph[p.st][i])
		{
			min1 = graph[p.st][i];
		}
	}
	ret += min1;
	//从终点到最近未遍历城市的距离  
	for (int i = 1; i <= n; i++)
	{
		if (p.vis[i] == 0 && min2>graph[p.ed][i])
		{
			min2 = graph[p.ed][i];
		}
	}
	ret += min2;
	//进入并离开每个未遍历城市的最小成本  
	for (int i = 1; i <= n; i++)
	{
		if (p.vis[i] == 0)
		{
			min1 = min2 = INF;
			for (int j = 1; j <= n; j++)
			{
				if (min1>graph[i][j])
					min1 = graph[i][j];
			}
			for (int j = 1; j <= n; j++)
			{
				if (min2>graph[j][i])
					min2 = graph[j][i];
			}
			ret += min1 + min2;
		}
	}
	//向上取整  
	return ret % 2 == 0 ? (ret / 2) : (ret / 2 + 1);
}

//graph中每一行最小的2个元素的平均数作为下界  
void get_low()
{
	low = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp[CityNum];
		for (int j = 1; j <= n; j++)
		{
			temp[j] = graph[i][j];
		}
		sort(temp + 1, temp + 1 + n);
		low = low + temp[1] + temp[2];
	}
	low = low / 2;
	//cout << "low:" << low << " ";
}

int solve()
{
	get_up();
	get_low();
	node start;
	start.st = 1;
	start.ed = 1;
	start.k = 1;
	for (int i = 1; i <= n; i++)
		start.vis[i] = 0;
	start.vis[1] = 1;
	start.sumv = 0;
	start.lb = low;
	int ret = INF;
	q.push(start);
	node next, temp;
	while (!q.empty())
	{
		temp = q.top();
		q.pop();
		if (temp.k == n - 1) //如果只剩最后一个点了  
		{
			int pos = 0;
			for (int i = 1; i <= n; i++)
			{
				if (temp.vis[i] == 0)
				{
					pos = i;
					break;
				}
			}
			if (pos == 0) break;
			int ans = temp.sumv + graph[pos][temp.st] + graph[temp.ed][pos];
			node judge = q.top();
			//如果当前的路径和比所有的目标函数值都小则跳出并直接输出最优解   
			if (ans <= judge.lb)
			{
				ret = min(ans, ret);
				break;
			}
			//否则继续求其他可能的路径和并更新上界  
			else
			{
				up = min(up, ans);
				ret = min(ret, ans);
				continue;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (temp.vis[i] == 0)
			{
				next.st = temp.st;
				next.sumv = temp.sumv + graph[temp.ed][i];
				next.ed = i;
				next.k = temp.k + 1;
				for (int j = 1; j <= n; j++) 
					next.vis[j] = temp.vis[j];
				next.vis[i] = 1;
				next.lb = get_lb(next);
				if (next.lb >= up) continue;
				q.push(next);
			}
		}
	}
	return ret;
}

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
	n = stoi(sN);
	cityArray = new City[n+1];
	for (size_t i = 1; i <= n; i++)
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
	for (size_t i = 1; i <= n; i++)
		cout << cityArray[i].num << " " << cityArray[i].x << " " << cityArray[i].y << endl;
	ios::sync_with_stdio(false);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) graph[i][j] = INF;
			else graph[i][j] = ceil(sqrt((cityArray[i].x - cityArray[j].x)*(cityArray[i].x - cityArray[j].x) + (cityArray[i].y - cityArray[j].y)*(cityArray[i].y - cityArray[j].y)));
		}
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << graph[i][j] << "    ";
		}
		cout << endl;
	}
	*/
	cout << solve() << endl;
	system("pause");
	return 0;
}
