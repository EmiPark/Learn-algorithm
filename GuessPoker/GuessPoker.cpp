// GuessPoker.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
bool isScr = true;
bool ANS;
void char2bool(char c);
int findMid(int left, int right);

int main()
{
	int leftNum = 1, rightNum = 10, midNum = 11;
	int mark = 0;	//mark=0��������δ����,mark=1������������
	int num12, num34;
	char ans;

	cout << "�����������˿��ƣ�Ȼ��ش������������⣬ֻ������Y�������ǣ�����N�������" << endl;
	while (mark != 1)
	{
		//�������if���ֻʣ��4����ʱ�жϻ�����BUG
		//if ((leftNum - midNum == 1) && (rightNum - midNum == 2))
		//{
		//	midNum = leftNum;
		//	ANS = true;
		//	break;
		//}
		cout << "�ǻ����𣨰�����С����" << endl;
		cin >> ans;
		char2bool(ans);
		if (ANS)
		{

		}
		else
		{
			midNum = findMid(leftNum, rightNum);
			if (midNum == leftNum || midNum == rightNum) mark = 1;
			else if (mark == 0)
			{
				cout << "���������·�Χ��" << leftNum << "-" << midNum << "(����" << leftNum << "��" << midNum << ")" << endl;
				cin >> ans;
				char2bool(ans);
				if (ANS) rightNum = midNum;
				else leftNum = midNum + 1;
			}
		}
	}
	if (!ANS)  num12 = midNum;
	else
	{
		cout << "ǰ��λ����" << midNum << "��" << endl;
		cin >> ans;
		char2bool(ans);
		if (ANS) num12 = midNum;
		else  num12 = midNum + 1;
	}
	cout << endl;
    return 0;
}
int findMid(const int left, const int right)
{
	return (left + right) / 2;
}
void char2bool(char c)
{
	while (!(c == 'Y' || c == 'y' || c == 'N' || c == 'n'))
	{
		cout << "������������������" << endl;
		cin >> c;
	}
	if (c == 'Y' || c == 'y')
		ANS = true;
	else if (c == 'N' || c == 'n')
		ANS = false;
}
