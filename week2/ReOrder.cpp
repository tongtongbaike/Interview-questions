//��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
//�����Ƚϼ򵥣���Ҫ��ʵ��ָ������ǰ�󿿽�����������ż������������������������
//��Ҫ������Ŀ�����ͽ��н��������Լ򵥵�˼·ֻҪ��������������ʵ�����õĽ����ԾͿ����ˡ�ֱ���ϴ���ɡ�

#include<iostream>
using namespace std;

void Reorder(int *pData, unsigned int length, bool(*func)(int))
{
	if (pData == NULL || length == 0)
	{
		return;
	}
	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;
		while (pBegin < pEnd && func(*pBegin))
			pEnd--;

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n & 1 == 0);
}

void ReorderOddEven(int *pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}



int main()
{
	int arry[] = { 9, 11, 20, 17, 16, 3, 7, 8, 99 };
	ReorderOddEven(arry, sizeof(arry));
	for (int i = 0; i < sizeof(arry); ++i)
	{
		cout << arry[i]<<" ";
	}
	cout << endl;
	return 0;
}