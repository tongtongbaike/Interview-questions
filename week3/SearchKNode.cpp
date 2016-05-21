//寻找链表的倒数第K个节点；
//这个题的思路非常简单，我们只需要先走K-1个节点，然后在让一个节点指针在开头，然后两个指针同时往前跳。
//当指针走到节点尾端的时候，就找到了倒数第K个节点了。
//所以只写出了简单的函数。

#include<iostream>
#include<assert.h>
using namespace std;

ListNode* SearchKNode(ListNode* pListHead, int k)
{
	if (k == 0 || pListHead == NULL)
	{
		return NULL;
	}


	ListNode* pCurHead = pListHead;
	ListNode* pBegin = pListHead;

	for (int i = 0; i < k - 1; ++i)
	{
		if (pCurHead->_next != NULL)
			pCurHead = pCurHead->_next;
		else
			return NULL;
	}

	while (pCurHead->_next != NULL)
	{
		pCurHead = pCurHead->_next;
		pBegin = pBegin->_next;
	}
	return pBegin;

}
