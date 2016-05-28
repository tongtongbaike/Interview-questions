//所有树的问题都是分化问题。
//对于一个二叉查找树的后序遍历来说，root节点是在数组中的最后一个节点.
//二叉查找树而言，左子树永远小于根节点，右子树永远大于根节点，所以我们利用最后一个节点值进行比较。
//然后不断缩小范围，直到我们的数据长度为1.
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

