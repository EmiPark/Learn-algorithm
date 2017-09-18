// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#define INFINITY_MAX 10000
using namespace std;
template<class elemType>
elemType* vec2arr(vector<elemType> vec);
template<class elemType>
void quickSort(elemType a[], int begin, int end);
void greedy(int *arr, int arrSize, int remaning);
void dynamic(int *arr, int arrSize, int money);
int main()
{
	int money;
	string input;		//��ȡ������
	vector<int>  A;
	A.reserve(1);		//����capacityΪ1��֮�����Ԫ�ض�̬��չ�ռ���Ԫ��
	cout << "����POS���д��еĻ��ң���Ϊ������������#����" << endl;
	while (true)
	{
		cin >> input;		//ע��ֱ����>>��ȡstring��Ҫstringͷ�ļ�
		if (input == "#") break;
		else A.push_back(atoi(input.c_str()));
	}
	int *arr = new int[1];		//new��ʼ������ָ�������С
	arr = vec2arr(A);
	quickSort(arr, 0, A.size() - 1);
	cout << "������֧���Ľ�" << endl;
	cin >> money;
	cout << "̰���㷨��⣺" << endl;
	cout << "---------------------------------------------------------" << endl;
	greedy(arr, A.size(), money);
	cout << "---------------------------------------------------------" << endl;
	cout << "��̬�滮��⣺" << endl;
	cout << "---------------------------------------------------------" << endl;
	dynamic(arr, A.size(), money);
	cout << "---------------------------------------------------------" << endl;
	system("pause");
    return 0;
}
template<class elemType>
elemType* vec2arr(vector<elemType> vec)
{
	elemType* arr = new elemType[vec.size()];
	for (size_t i = 0; i < vec.size(); i++)
		arr[i] = vec[i];
	return arr;
}
template<class elemType>
void quickSort(elemType a[], int begin, int end)		//�Ӵ�С�Ŀ���
{
	if (begin < end)
	{
		int i = begin, j = end;
		elemType key = a[i];
		while (i<j)
		{
			while (i<j&&a[j]<key)		j--;	//j��ǰ�ұ�keyС������ע����ʱ���i<j
			if (i < j)		a[i++] = a[j];
			while (i < j&&a[i] > key)		i++;	 //i����ұ�key�����
			if (i < j)		a[j--] = a[i];
		}
		//��key��ֵ��i��j�����ĵط�
		a[i] = key;
		//����ݹ�
		quickSort(a, begin, i - 1);
		quickSort(a, i + 1, end);
	}
}
void greedy(int *arr,int arrSize,int remaning)
{
	int paid = 0;		//�Ѹ����
	int needPay = remaning;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (remaning == 0)	break;
		else 
		{
			if (remaning >= arr[i])
			{
				paid += arr[i];
				remaning -= arr[i];
				cout << "֧��һ��" << arr[i] << "Ԫ���ҡ�" << endl;
			}
			else continue;
		}
	}
	if (paid==needPay)
		cout << "֧����ɣ�" << endl;
	else cout << "POS���ڻ��Ҳ��㣬֧��ʧ�ܣ�" << endl;
}
//�ο����£�http://blog.csdn.net/wdxin1322/article/details/9501163
void dynamic(int *values, int types, int total, int coinUsed[], int cointTrack[]) 
{
	coinUsed[0] = 0;
	cointTrack[0] = 0;
	for (int i = 1; i <= total; i++)
	{
		int mincoin = i;
		int lastin = 0;
		for (int j = 0; j < types; j++) {
			if (values[j] <= i) {
				if (coinUsed[i - values[j]] + 1 < mincoin) {
					mincoin = coinUsed[i - values[j]] + 1;
					lastin = values[j];
				}
			}
		}
		coinUsed[i] = mincoin;
		cointTrack[i] = lastin;
	}
	while (total>0)
	{
		cout << cointTrack[total] << " ";
		total -= cointTrack[total];
	}
}

void dynamic(int *cashArr, int arrSize, int money)			//����Ѿ��Ӵ�С�ź����������ж�̬�滮
{
	int cur = INFINITY_MAX, i = 0, typeSize = 0;
	int *typeArr = new int[arrSize*2];		//����ͳ�ƻ��ҵ����ࡢÿ������ĸ�����ÿ���������ֵ
	for (; i < arrSize*2; i++)
			typeArr[i] = 0; 
	i = 0;
	for (size_t k = 0; k < arrSize; k++)
	{
		if (cashArr[k]<cur)
		{
			typeSize++;
			typeArr[++i]++;
			typeArr[arrSize+i] = cashArr[k];  //��typeArr[arrSize+i]���洢ÿ�ֻ��ҵ���ֵ
			cur = cashArr[k]; 
		}
		else typeArr[i]++;
	}
	//for (size_t k = 1; k <= typeSize; k++)
	//	cout << "��" << k << "�ֻ�����" << typeArr[k] << "��" << ",����ֵΪ" <<typeArr[arrSize+k]<< endl;
	//��ʼ��̬�滮
	//ֻ�ܾ�ÿ�ֻ��Ҹ������޵�������ж�̬�滮����δ�ҵ����ƻ�������ʱ�ĸĽ�����
	int * used = new int[money+1];
	int * track = new int[money+1];
	for (size_t m = 1; m <= money; m++)
	{
		int min = m; 
		int lastin = 0;
		//int *recNum = new int[typeSize];
		for (size_t n = 1; n <= typeSize; n++)
		{
			if (typeArr[arrSize +n] <= m)
			{
				if (used[m-typeArr[arrSize +n]]+1<min)
				{
						min = used[m - typeArr[arrSize + n]] + 1;
						lastin = typeArr[arrSize + n];
				}
			}
		}
		used[m] = min;
		track[m] = lastin;
	}
	while (money>0)
	{
		cout <<"֧��һ��"<< track[money] << "Ԫ����" << endl;
		money -= track[money];
	}
	if (money == 0) cout << "֧���ɹ���" << endl;
	else cout << "POS���ڻ��Ҳ��㣬֧��ʧ�ܣ�" << endl;
}