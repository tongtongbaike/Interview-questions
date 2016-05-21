//合并有序单链表，这个问题其实也是比较简单的，跟判断2个单链表中相同的值是同样的道理、
//比较两个单链表，小的插入到新链表中，然后指针向后跳，然后当两个指针都走到结尾，其中链表返回没有走完的链表就可以了。
//就写一个简单的函数代码。
#include<iostream>
using namespace std;

ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	if (pHead2 == NULL)
	{
		return pHead1;
	}

	ListNode* pMergedHead = NULL;
	if (pHead1->m_nvalue > pHead2->m_nvalue)
	{
		pMergedHead = pHead2;
		pMergedHead->m_pNext = MergeList(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMergedHead = pHead1;
		pMergedHead->m_pNext = MergeList(pHead1, pHead->m_pNext);
	}
	return pMergedHead;
}