// 最长公共子序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#define N 100
using namespace std;
int getMaxSubSequenceCount(char *a, int lenA, char *b, int lenB);
stack<char> myStack;
int main()
{
	string str;
	char a[N], b[N];
	cout << "为a字符串赋值，以#结束" << endl;
	getline(cin, str, '#');
	strcpy(a, str.c_str());
	cout << "为b字符串赋值，以#结束" << endl;
	getline(cin, str, '#');
	strcpy(b, str.c_str());
	cout << endl;
	/*int i = 0, j = 0;
	while (a[i] != '\0')
		cout << a[i++];
	cout << endl;
	while (b[j] != '\0')
		cout << b[j++];*/
	cout << endl;
	cout << "最长公共子序列的个数为：" <<getMaxSubSequenceCount(a, strlen(a), b, strlen(b)) << endl;
	system("pause");
    return 0;
}

int getMaxSubSequenceCount(char *a, int lenA, char *b, int lenB) 
{
	int len[N][N];
	for (int i = 0; i<lenA; i++) {
		if (a[i] == b[0])
			len[i][0] = 1;
		else {
			if (i>0) len[i][0] = len[i - 1][0];
			else len[i][0] = 0;
		}
	}

	for (int j = 0; j<lenB; j++) {
		if (a[0] == b[j])
			len[0][j] = 1;
		else {
			if (j>0) len[0][j] = len[0][j - 1];
			else len[0][j] = 0;
		}
	}

	int maxLen = 0;
	for (int i = 1; i<lenA; i++) {
		for (int j = 1; j<lenB; j++) {
			if (a[i] == b[j])
				len[i][j] = len[i - 1][j - 1] + 1;
				
			else
			{
				if (len[i - 1][j] > len[i][j - 1]) len[i][j] = len[i - 1][j];
				else len[i][j] = len[i][j - 1];
			}

			if (len[i][j] > maxLen) maxLen = len[i][j];
		}
	}
	return maxLen;
}