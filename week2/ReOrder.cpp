//题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
//这个题比较简单，主要是实现指针两端前后靠近。发现奇数偶数（正负，或者其他条件）
//需要满足题目条件就进行交换。所以简单的思路只要我们满足条件，实现良好的解耦性就可以了。直接上代码吧。

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