// ��ѵ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//�ο����ף�http://blog.csdn.net/xiaowang627/article/details/55851988

void output(int x[]);
void BackTrack(int task);
int getTime(int *time_mac);
void output_assign(int *best_x);

int NUM_TASK, NUM_MAC;
int min_t = INT_MAX;										 //ִ�������������Сʱ��  
int *x, *best_x, *t, *time_mac;								 
//x�����ʾ������task�������x[task]  			 
//best_x����洢���ŷ��䷽��  
//t����洢ÿ����������ʱ��  
//time_mac�洢ÿ���������н�����ʱ��  

int main() 
{
	string s_task, s_mac,s_tArray;
	stringstream ss(s_tArray);
	int temp;
	ifstream input("input.txt");
	while (!input.is_open())
	{
		cout << "�ļ������ڣ����ݼ���ȡʧ�ܣ�" << endl;
		return 0;
	}
	cout << "���ݼ���ȡ�ɹ���" << endl;
	getline(input, s_task);
	NUM_TASK = stoi(s_task);
	getline(input, s_mac);
	NUM_MAC = stoi(s_mac);
	getline(input, s_tArray);
	cout << "��������" << NUM_TASK << " ��������" << NUM_MAC << endl;
	x = new int[NUM_TASK + 1];
	best_x = new int[NUM_TASK + 1];
	t= new int[NUM_TASK + 1];
	time_mac = new int[NUM_MAC + 1];
	//��ȡ����һ��stringת��Ϊint����
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
	cout << "��������ִ��ʱ������Ϊ��" << endl;
	for (int i = 1; i <= NUM_TASK; i++) 
		cout << t[i] << " ";
	cout << endl;
	cout << "����Ҫ����Сʱ��Ϊ��" << min_t << endl;
	//output(best_x);  
	output_assign(best_x);
	system("pause");
	return 0;
}
void BackTrack(int task) 
{
	if (task > NUM_TASK)
	{
		int cur_time = getTime(time_mac);//��ǰ�ѷ�����������ʱ��  
		/*������з���������Լ���Ӧ��ʱ��*/
		output(x);  
		cout << "��ǰ�����µ����ʱ�䣺" << cur_time <<endl;  
		if (cur_time < min_t)
		{ //��֦  
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
		cout << "����" << i << "���������" << best_x[i] << endl;
}
