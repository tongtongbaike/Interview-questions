//栈的压入弹出序列，
//输入2个数组，一个压入序列，一个弹出序列，判断弹出序列是不是栈的弹出序列。
//栈是先进后出的序列，所以面对弹出序列时，我们需要不断地压入数据进入栈。
//每一次压入都要检测是不是当前数据的弹出数据，然后如果对比成功就弹出数据，poparry向后移动。
//需要注意的是我们的完成判断条件
//1.成功:
//判断指针与首部指针差值为长度 && 创建的压入栈为空
//2.失败：
// （1）：当压入所有压入栈序列任然没有匹配到对于弹出数据 && 栈顶不等于弹出序列
//这个题只需要根据题的字面意思、我们进行设置判断，压入一个

#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

bool IsPopOrder(int *pPush, int *pPop, int nLength)
{
	assert(pPush && pPop);
	bool ret = false;

	if (nLength < 0)
	{
		return ret;
	}

	std:: stack<int> stackData;
	const int *pPushNext = pPush;
	const int *pPopNext = pPop;
	while (pPopNext - pPop < nLength)
	{
		while (stackData.empty() || stackData.top() != *pPopNext)
		{
			if (pPushNext - pPush == nLength)
			{
				break;
			}
			stackData.push(*pPushNext);
			++pPushNext;
		}

		if (stackData.top() != *pPopNext)
		{
			break;
		}

		stackData.pop();
		++pPopNext;
	}
	if (stackData.empty() && pPopNext - pPop == nLength)
	{
		ret = true;
	}

	return ret;
}

void test()
{
	int arry[] = { 1, 2, 3, 4, 5 };
	int arry2[] = { 4, 5, 3, 2, 1 };
	int arry3[] = { 4, 3, 5, 1, 2 };
	if (IsPopOrder(arry, arry2, 5))
	{
		printf("arry2 is arry pop arry\n");
	}
	else{
		printf("arry2 not arry pop arry\n");
	}

	if (IsPopOrder(arry, arry3, 5))
	{
		printf("arry3 is arry pop arry\n");
	}
	else{
		printf("arry3 not arry pop arry\n");
	}
}

int main()
{
	test();
	return 0;
}