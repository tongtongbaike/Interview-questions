//ջ��ѹ�뵯�����У�
//����2�����飬һ��ѹ�����У�һ���������У��жϵ��������ǲ���ջ�ĵ������С�
//ջ���Ƚ���������У�������Ե�������ʱ��������Ҫ���ϵ�ѹ�����ݽ���ջ��
//ÿһ��ѹ�붼Ҫ����ǲ��ǵ�ǰ���ݵĵ������ݣ�Ȼ������Աȳɹ��͵������ݣ�poparry����ƶ���
//��Ҫע��������ǵ�����ж�����
//1.�ɹ�:
//�ж�ָ�����ײ�ָ���ֵΪ���� && ������ѹ��ջΪ��
//2.ʧ�ܣ�
// ��1������ѹ������ѹ��ջ������Ȼû��ƥ�䵽���ڵ������� && ջ�������ڵ�������
//�����ֻ��Ҫ�������������˼�����ǽ��������жϣ�ѹ��һ��

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