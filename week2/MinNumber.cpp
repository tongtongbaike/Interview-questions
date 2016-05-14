#include<iostream>
#include<assert.h>
using namespace std;

int Min(int *arry, int length)
{
	assert(arry);
	if (length < 0)
	{
		cout << "���ȳ��ִ���" << endl;
		return 0;
	}
	int indexStart = 0;
	int indexEnd = length - 1;
	//��ֹһ��ʼ����ת0;
	int indexMid = indexStart;

	while (arry[indexStart] >= arry[indexEnd])
	{
		//�����еڶ�������ǰ��С������ת������ת����ڵ�һ��ָ����ڵڶ���ָ�롣
		if (indexEnd - indexStart == 1)
		{
			indexMid = indexEnd;
			break;
		}
		indexMid = indexStart + (indexEnd - indexStart) / 2;
		//Ҫ���ǵ������д�����������������
		if (arry[indexMid] == arry[indexStart] && arry[indexStart] == arry[indexEnd])
		{
			return MinInorder(arry,indexStart, indexEnd);
		}
		//�������С�ж�����;
		if (arry[indexMid] <= arry[indexEnd])
		{
			indexEnd = indexMid;
		}
		else if(arry[indexMid] >= arry[indexStart])
		{
			indexStart = indexMid;
		}

		return arry[indexMid];
	}
}

int MinInrder(int *arry, int indexStart, int indexEnd)
{
	int result = arry[indexStart];
	for (int i = indexStart + 1; i <= indexEnd; ++i)
	{
		if (result > arry[i])
		{
			result = arry[i];
		}
	}
	return result;
}

int main()
{
	int arry[] = { 3, 4, 5, 1, 2 };
	int minNumber = Min(arry, 5);
	return 0;
}