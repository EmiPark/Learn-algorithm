// GuessNumber.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int mark = 0;	//mark=0��������δ����,mark=1������������
	int num12, num34, num56;
	char ans;
	cout << "������һ����λʮ����������Ȼ��ش������������⣬ֻ������Y�������ǣ�����N�������" << endl;
	while (mark!=1)
	{
		//�������if���ֻʣ��4����ʱ�жϻ�����BUG
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
			cout << "ǰ��λ�������·�Χ��" << leftNum << "-" << midNum <<"(����"<<leftNum<<"��"<<midNum<<")" <<endl;
			cin >> ans;
			char2bool(ans);
			if (ANS) rightNum = midNum;
			else leftNum = midNum+1;
		}
	}
	if (!ANS)  num12 = midNum;
	else
	{
		cout << "ǰ��λ����" << midNum << "��" << endl;
		cin >> ans;
		char2bool(ans);
		if (ANS) num12= midNum;
		else  num12 = midNum+1;
	}
	//��ȡ�м���λ
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
			cout << "�м���λ�������·�Χ��" << leftNum << "-" << midNum << "(����" << leftNum << "��" << midNum << ")" << endl;
			cin >> ans;
			char2bool(ans);
			if (ANS) rightNum = midNum;
			else	leftNum = midNum + 1;
		}
	}
	if (!ANS)  num34 = midNum;
	else
	{
		cout << "�м���λ����" << midNum << "��" << endl;
		cin >> ans;
		char2bool(ans);
		if (ANS) num34 = midNum;
		else  num34 = midNum + 1;
	}
	cout << endl;
	//��ȡ�����λ
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
			cout << "�����λ�������·�Χ��" << leftNum << "-" << midNum << "(����" << leftNum << "��" << midNum << ")" << endl;
			cin >> ans;
			char2bool(ans);
			if (ANS) rightNum = midNum;
			else	leftNum = midNum + 1;
		}
	}
	if (!ANS)  num56 = midNum;
	else
	{
		cout << "�м���λ����" << midNum << "��" << endl;
		cin >> ans;
		char2bool(ans);
		if (ANS) num56 = midNum;
		else  num56 = midNum + 1;
	}
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << "����������ǣ�" << num12 * 10000 + num34 * 100 + num56 << endl;
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
		cout << "������������������" << endl;
		cin >> c;
	}
	if (c == 'Y' || c == 'y')
		ANS = true;
	else if (c == 'N' || c == 'n')
		ANS = false;
}
