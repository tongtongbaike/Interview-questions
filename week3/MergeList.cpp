//�ϲ������������������ʵҲ�ǱȽϼ򵥵ģ����ж�2������������ͬ��ֵ��ͬ���ĵ���
//�Ƚ�����������С�Ĳ��뵽�������У�Ȼ��ָ���������Ȼ������ָ�붼�ߵ���β������������û�����������Ϳ����ˡ�
//��дһ���򵥵ĺ������롣
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