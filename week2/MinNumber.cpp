#include<iostream>
#include<assert.h>
using namespace std;

int Min(int *arry, int length)
{
	assert(arry);
	if (length < 0)
	{
		cout << "长度出现错误" << endl;
		return 0;
	}
	int indexStart = 0;
	int indexEnd = length - 1;
	//防止一开始就旋转0;
	int indexMid = indexStart;

	while (arry[indexStart] >= arry[indexEnd])
	{
		//序列中第二个代表当前最小数；旋转序列旋转后存在第一个指针大于第二个指针。
		if (indexEnd - indexStart == 1)
		{
			indexMid = indexEnd;
			break;
		}
		indexMid = indexStart + (indexEnd - indexStart) / 2;
		//要考虑到数组中存在若干相等数的情况
		if (arry[indexMid] == arry[indexStart] && arry[indexStart] == arry[indexEnd])
		{
			return MinInorder(arry,indexStart, indexEnd);
		}
		//否则就缩小判断区间;
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