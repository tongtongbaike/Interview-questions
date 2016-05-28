//�����������ⶼ�Ƿֻ����⡣
//����һ������������ĺ��������˵��root�ڵ����������е����һ���ڵ�.
//������������ԣ���������ԶС�ڸ��ڵ㣬��������Զ���ڸ��ڵ㣬���������������һ���ڵ�ֵ���бȽϡ�
//Ȼ�󲻶���С��Χ��ֱ�����ǵ����ݳ���Ϊ1.
#include<iostream>
#include<assert.h>
using namespace std;

bool IsPostOrderArrayToBST(int *arry,int length)
{
	assert(arry);
	int root = arry[length - 1];
	int i = 0;
	for (; i < length; ++i)
	{
		if (arry[i] > root)
		{
			break;
		}
	}
	int j = i;
	for (; j < length; ++j)
	{
		if (arry[j] < root)
		{
			return false;
		}
	}
	bool retLeft = true;
	if (i > 0)
	{
		retLeft = 	IsPostOrderArrayToBST(arry, i);
	}
	bool retRight = true;
	if (i > 0)
	{
		retRight = IsPostOrderArrayToBST(arry + i, length - i + 1);
	}
	return	(retLeft && retRight);
}

void Test()
{
	int arry[] = { 5, 7, 6, 9, 11, 10, 8 };
	if (IsPostOrderArrayToBST(arry, sizeof(arry)))
	{
		printf("PostArry  is BST \n");
	}
	else
	{
		printf("PostArry not BST\n");
	}
}

int main()
{
	Test();
	return 0;
}

