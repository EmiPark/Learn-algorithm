// 最佳调度问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//参考文献：http://blog.csdn.net/xiaowang627/article/details/55851988

void output(int x[]);
void BackTrack(int task);
int getTime(int *time_mac);
void output_assign(int *best_x);

int NUM_TASK, NUM_MAC;
int min_t = INT_MAX;										 //执行任务所需的最小时间  
int *x, *best_x, *t, *time_mac;								 
//x数组表示给任务task分配机器x[task]  			 
//best_x数组存储最优分配方案  
//t数组存储每个任务所需时间  
//time_mac存储每个机器运行结束的时间  

int main() 
{
	string s_task, s_mac,s_tArray;
	stringstream ss(s_tArray);
	int temp;
	ifstream input("input.txt");
	while (!input.is_open())
	{
		cout << "文件不存在，数据集读取失败！" << endl;
		return 0;
	}
	cout << "数据集读取成功！" << endl;
	getline(input, s_task);
	NUM_TASK = stoi(s_task);
	getline(input, s_mac);
	NUM_MAC = stoi(s_mac);
	getline(input, s_tArray);
	cout << "任务数：" << NUM_TASK << " 机器数：" << NUM_MAC << endl;
	x = new int[NUM_TASK + 1];
	best_x = new int[NUM_TASK + 1];
	t= new int[NUM_TASK + 1];
	time_mac = new int[NUM_MAC + 1];
	//读取到的一行string转换为int数组
	ss << s_tArray;
	for (size_t i = 1; i <= NUM_TASK; i++)
	{
		ss >> temp;
		t[i] = temp;
	}
	t[0] = 0;
	for (size_t i = 0; i <= NUM_TASK; i++)
		time_mac[i] = 0;
	BackTrack(1);
	cout << "各个任务执行时间依次为：" << endl;
	for (int i = 1; i <= NUM_TASK; i++) 
		cout << t[i] << " ";
	cout << endl;
	cout << "所需要的最小时间为：" << min_t << endl;
	//output(best_x);  
	output_assign(best_x);
	system("pause");
	return 0;
}
void BackTrack(int task) 
{
	if (task > NUM_TASK)
	{
		int cur_time = getTime(time_mac);//当前已分配任务的完成时间  
		/*输出所有分配情况，以及对应的时间*/
		output(x);  
		cout << "当前分配下的完成时间：" << cur_time <<endl;  
		if (cur_time < min_t)
		{ //剪枝  
			min_t = cur_time;
			for (int i = 1; i <= NUM_TASK; i++)
				best_x[i] = x[i];
		}
	}
	else 
	{
		for (int i = 1; i <= NUM_MAC; i++)
		{
			x[task] = i;
			time_mac[i] += t[task];
			if (time_mac[i]<min_t)
				BackTrack(task + 1);
			time_mac[i] -= t[task];
		}
	}
}

void output(int x[])
{
	for (int i = 1; i <= NUM_TASK; i++) 
		cout << x[i] << " ";
	cout << endl;
}

int getTime(int *time_mac)
{
	int max_time = time_mac[1];
	for (int i = 2; i <= NUM_MAC; i++) 
	{
		if (time_mac[i] > max_time)
			max_time = time_mac[i];
	}
	return max_time;
}

void output_assign(int *best_x) 
{
	for (int i = 1; i <= NUM_TASK; i++)
		cout << "任务" << i << "分配给机器" << best_x[i] << endl;
}
