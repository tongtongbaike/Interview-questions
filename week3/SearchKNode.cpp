//Ѱ������ĵ�����K���ڵ㣻
//������˼·�ǳ��򵥣�����ֻ��Ҫ����K-1���ڵ㣬Ȼ������һ���ڵ�ָ���ڿ�ͷ��Ȼ������ָ��ͬʱ��ǰ����
//��ָ���ߵ��ڵ�β�˵�ʱ�򣬾��ҵ��˵�����K���ڵ��ˡ�
//����ֻд���˼򵥵ĺ�����

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
