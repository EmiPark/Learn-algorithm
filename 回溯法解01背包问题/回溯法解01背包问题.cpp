// ���ݷ���01��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<class elemType>
elemType* vec2arr(vector<elemType> vec);
void backtrack(int i);
double bound(int i);
int n;//��Ʒ����
double c;//��������
double *v = new double[1];
double *w = new double[1];
double cw = 0.0;//��ǰ��������
double cp = 0.0;//��ǰ��������Ʒ��ֵ
double bestp = 0.0;//��ǰ���ż�ֵ
int put[100];//�����Ƿ�װ��

int main()
{
	string input;		//��ȡ������
	vector<double>  wVec;
	vector<double>  vVec;
	wVec.reserve(1);		//����capacityΪ1��֮�����Ԫ�ض�̬��չ�ռ���Ԫ��
	vVec.reserve(1);
	int mark = 0;
	cout << "��������ÿһ����Ʒ�������ͼ�ֵ����#����" << endl;
	while (true)
	{
		cin >> input;		//ע��ֱ����>>��ȡstring��Ҫstringͷ�ļ�
		if (input == "#") break;
		else
		{
			if (mark == 0)
			{
				wVec.push_back(atoi(input.c_str()));
				mark = 1;
			}
			else
			{
				vVec.push_back(atoi(input.c_str()));
				mark = 0;
			}
		}
	}
	n = vVec.size();
	cout << "���뱳����������" << endl;
	cin >> c;
	w= vec2arr(wVec);
	v = vec2arr(vVec);
	backtrack(1);
	cout <<"�����ɷ��������ֵ�ǣ�"<< bestp << endl;
	system("pause");
	return 0;
}

//���ݺ���
void backtrack(int i)
{
	if (i>n)
	{
		bestp = cp;
		return;
	}
	if (cw + w[i] <= c)
	{
		cw += w[i];
		cp += v[i];
		put[i] = 1;
		backtrack(i + 1);
		cw -= w[i];
		cp -= v[i];
	}
	if (bound(i + 1)>bestp)//������������������
		backtrack(i + 1);
}

//�����Ͻ纯��
double bound(int i)
{
	double leftw = c - cw;
	double b = cp;
	while (i <= n&&w[i] <= leftw)
	{
		leftw -= w[i];
		b += v[i];
		i++;
	}
	if (i <= n)
		b += v[i] / w[i] * leftw;
	return b;
}

template<class elemType>
elemType* vec2arr(vector<elemType> vec)
{
	elemType* arr = new elemType[vec.size()];
	for (size_t i = 0; i < vec.size(); i++)
		arr[i] = vec[i];
	return arr;
}