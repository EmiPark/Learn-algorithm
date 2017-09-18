// GuessNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
bool ANS;
void char2bool(char c);
int findMid(int left, int right);
int main()
{
	int leftNum = 0, rightNum = 99, midNum=100;
	int mark = 0;	//mark=0代表问题未问完,mark=1代表问题问完
	int num12, num34, num56;
	char ans;
	cout << "请设想一个六位十进制整数，然后回答程序提出的问题，只能输入Y（代表是）或者N（代表否）" << endl;
	while (mark!=1)
	{
		//下面这个if解决只剩下4个数时判断会出错的BUG
		if ((leftNum - midNum == 1)&&(rightNum-midNum==2))
		{
			midNum = leftNum;
			ANS = true;
			break;
		}
		else midNum = findMid(leftNum, rightNum);
		if (midNum == leftNum||midNum==rightNum) mark = 1;
		else if (mark==0)
		{
			cout << "前两位数在以下范围吗：" << leftNum << "-" << midNum <<"(包括"<<leftNum<<"和"<<midNum<<")" <<endl;
			cin >> ans;
			char2bool(ans);
			if (ANS) rightNum = midNum;
			else leftNum = midNum+1;
		}
	}
	if (!ANS)  num12 = midNum;
	else
	{
		cout << "前两位数是" << midNum << "吗？" << endl;
		cin >> ans;
		char2bool(ans);
		if (ANS) num12= midNum;
		else  num12 = midNum+1;
	}
	//获取中间两位
	leftNum = 0; 
	rightNum = 99;
	mark = 0;
	while (mark != 1)
	{
		if ((leftNum - midNum == 1) && (rightNum - midNum == 2))
		{
			midNum = leftNum;
			ANS = true;
			break;
		}
		else midNum = findMid(leftNum, rightNum);
		if (midNum == leftNum || midNum == rightNum) mark = 1;
		else if (mark == 0)
		{
			cout << "中间两位数在以下范围吗：" << leftNum << "-" << midNum << "(包括" << leftNum << "和" << midNum << ")" << endl;
			cin >> ans;
			char2bool(ans);
			if (ANS) rightNum = midNum;
			else	leftNum = midNum + 1;
		}
	}
	if (!ANS)  num34 = midNum;
	else
	{
		cout << "中间两位数是" << midNum << "吗？" << endl;
		cin >> ans;
		char2bool(ans);
		if (ANS) num34 = midNum;
		else  num34 = midNum + 1;
	}
	cout << endl;
	//获取最后两位
	leftNum = 0;
	rightNum = 99;
	mark = 0;
	while (mark != 1)
	{
		if ((leftNum - midNum == 1) && (rightNum - midNum == 2))
		{
			midNum = leftNum;
			ANS = true;
			break;
		}
		else midNum = findMid(leftNum, rightNum);
		if (midNum == leftNum || midNum == rightNum) mark = 1;
		else if (mark == 0)
		{
			cout << "最后两位数在以下范围吗：" << leftNum << "-" << midNum << "(包括" << leftNum << "和" << midNum << ")" << endl;
			cin >> ans;
			char2bool(ans);
			if (ANS) rightNum = midNum;
			else	leftNum = midNum + 1;
		}
	}
	if (!ANS)  num56 = midNum;
	else
	{
		cout << "中间两位数是" << midNum << "吗？" << endl;
		cin >> ans;
		char2bool(ans);
		if (ANS) num56 = midNum;
		else  num56 = midNum + 1;
	}
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << "您设想的数是：" << num12 * 10000 + num34 * 100 + num56 << endl;
	cout << "------------------------------------" << endl << endl;
	system("pause");
    return 0;
}
int findMid(const int left,const int right)
{
	return (left + right) / 2;
}
void char2bool(char c)
{
	while (!(c=='Y'|| c == 'y'|| c == 'N'||c == 'n'))
	{
		cout << "输入有误，请重新输入" << endl;
		cin >> c;
	}
	if (c == 'Y' || c == 'y')
		ANS = true;
	else if (c == 'N' || c == 'n')
		ANS = false;
}
