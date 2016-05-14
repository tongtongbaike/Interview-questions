#include "SLinkNode.h"
#include <malloc.h>
#include <assert.h>
void InitList(PLinkNode &pHead)
{
	pHead = NULL;
}
void PrintList(PLinkNode pHead)
{
	if(NULL == pHead)
	{
		printf("NULL\n");
		return;
	}
	while(NULL != pHead)
	{
		printf("%d->",pHead->_data);
		pHead =pHead->_next;
	}
	printf("NULL\n");
}
//返回0位空链表
int GetListLength(PLinkNode pHead)
{
	int length = 0;
	if(NULL == pHead)
	{
		return length;
	}
	while(NULL == pHead->_next)
	{
		++length;
		pHead = pHead->_next;
	}
	return length;
}
void DestoryLink(PLinkNode &pHead)
{
	PLinkNode del;
	assert(pHead);
	while(pHead != NULL)
	{
		del = pHead->_next;
		free(pHead);
		pHead = NULL;
		pHead = del;
	}
}
void PushBack(PLinkNode &pHead,DataType x)
{
	PLinkNode ins = pHead;
	if(NULL == pHead)
	{
		pHead = (PLinkNode)malloc(sizeof(LinkNode));
		pHead->_data = x;
		pHead->_next = NULL;
		return;
	}
	while(ins->_next != NULL)
	{
		ins = ins->_next;
	}
	ins->_next = (PLinkNode)malloc(sizeof(LinkNode));
	ins = ins->_next;
	ins->_next = NULL;
	ins->_data = x;
}
void PopBack(PLinkNode &pHead)
{
	PLinkNode failNode = pHead;
	PLinkNode del;
	if(pHead == NULL)
	{
		return;
	}
	if(pHead->_next == NULL)
	{
		del = pHead;
		pHead = NULL;
		free(del);
		del = NULL;
		return;
	}
	while(NULL != failNode->_next->_next)
	{
		failNode = failNode->_next;
	}
	del = failNode->_next->_next;
	failNode->_next = NULL;
	free(del);
	del = NULL;
}
void PushFront(PLinkNode &pHead,DataType x)
{
	PLinkNode insNode;
	if(NULL == pHead)
	{
		pHead = (PLinkNode)malloc(sizeof(LinkNode));
		pHead->_data = x;
		pHead->_next = NULL;
		return;
	}
	insNode = (PLinkNode)malloc(sizeof(LinkNode));
	insNode->_data = x;
	insNode->_next = pHead;
	pHead = insNode;
}
void PopFront(PLinkNode &pHead)
{
	PLinkNode del;
	if(NULL == pHead)
	{
		return;
	}
	del = pHead;
	pHead = pHead->_next;
	free(del);
	del = NULL;
}

PLinkNode Find(PLinkNode pHead,DataType x)
{
	PLinkNode ret;
	assert(pHead);
	ret = pHead;
	while(x != ret->_data && ret != NULL)
	{
		ret = ret->_next;
	}
	if(ret == NULL)
	{
		printf("链表没有此数据");
	}
	return ret;
}
void Insert(PLinkNode pos,DataType x)
{
	PLinkNode ins;
	assert(pos);
	ins = (PLinkNode)malloc(sizeof(LinkNode));
	ins->_data = pos->_data;
	pos->_data = x;

	ins->_next = pos->_next;
	pos->_next = ins;
}

//不能是尾节点。
void EraseNoHead(PLinkNode pos)
{
	PLinkNode del;
	assert(pos);
	pos->_data = pos->_next->_data;
	del = pos->_next;
	pos->_next = pos->_next->_next;
	free(del);
	del = NULL;
}
void Erase(PLinkNode &pHead,PLinkNode pos)
{
	PLinkNode posIndex = pHead;
	PLinkNode del = pHead;
	assert(pHead);
	assert(pos);
	if(pHead == pos)
	{
		pHead = pHead->_next;
		free(del);
		del = NULL;
		return;
	}
	while(posIndex->_next != pos && posIndex->_next != NULL)
	{
		posIndex = posIndex->_next;
	}
	posIndex->_next = pos->_next;
	free(pos);
	pos = NULL;
}

//对于更改的头指针地址变量来说，我们需要利用二级指针或者引用。
void DeleteNode(PLinkNode *pListHead,PLinkNode	pToBeDeleted)
{
	assert(pListHead && pToBeDeleted);
	//不是尾节点
	if (pToBeDeleted->_next != NULL)
	{
		PLinkNode pNext = pToBeDeleted->_next;
		pToBeDeleted->_data = pNext->_data;
		pToBeDeleted->_next = pNext->_next;
		delete pNext;
		pNext = NULL;
	}
	//头结点,只有一个
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	//尾节点
	else
	{
		PLinkNode pNode = *pListHead;
		while (pNode->_next != pToBeDeleted)
		{
			pNode = pNode->_next;
		}
		pNode->_next = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

void Remove(PLinkNode &pHead,DataType x)
{
	PLinkNode ergodic,del;
	assert(pHead);
	ergodic = pHead;
	while(ergodic->_data != x && ergodic != NULL)
	{
		ergodic = ergodic->_next;
	}
	del = ergodic->_next;
	ergodic->_data = ergodic->_next->_data;
	ergodic->_next = ergodic->_next->_next;
	free(del);
	del = NULL;
}
void RemoveAll(PLinkNode &pHead,DataType x)
{
	PLinkNode ergodic,del;
	assert(pHead);
	ergodic = pHead;
	while(ergodic != NULL)
	{
		if(ergodic->_data == x)
		{
			del = ergodic->_next;
			ergodic->_data = ergodic->_next->_data;
			ergodic->_next = ergodic->_next->_next;
			free(del);
			del = NULL;
		}
		ergodic = ergodic->_next;
	}
}
//有序列表，但是不确定是升序还是降序
void FindEqualData(PLinkNode oneHead,PLinkNode twoHead)
{
	//升序降序判断值，升序为0降序为1；
	int sortFlag = 0;
	assert(NULL != oneHead && NULL != twoHead);
	printf("相同的数据是:");
	if(oneHead->_data > oneHead->_next->_data)
	{
		sortFlag = 1;
	}
	while(oneHead != NULL && twoHead != NULL)
	{
		if(oneHead->_data > twoHead->_data)
		{
			if(1 == sortFlag)
			{
				oneHead = oneHead->_next;
			}
			else
			{
				twoHead = twoHead->_next;
		
			}
		}
		else if(oneHead->_data == twoHead->_data)
		{
			printf("%d ",oneHead->_data);
			twoHead = twoHead->_next;
			oneHead = oneHead->_next;
		}
		else if(oneHead->_data < twoHead->_data)
		{
			if(1 == sortFlag)
			{
				twoHead = twoHead->_next;
			}
			else
			{
				oneHead = oneHead->_next;
		
			}
		}
	}
}
//从尾到头打印单链表。利用递归打印。

void PrintFailToHead(PLinkNode pHead)
{
	if(pHead != NULL)
	{
		PrintFailToHead(pHead->_next);
		printf("%d->",pHead->_data);

	}
	if(pHead == NULL)
	{
		printf("NULL->");
		return;
	}
	return;
}

//约瑟夫环问题。已经是一个环。
void JosephRing(PLinkNode &pHead,DataType x)
{
	int count = 0;
	PLinkNode index = pHead,del;
	assert(pHead);
	while(index->_next != index)
	{
		for(count = 0;count < x - 1;count++)
		{
			index = index->_next;
		}
		del = index->_next;
		index->_data = index->_next->_data;
		index->_next = index->_next->_next;
		pHead = index;
		free(del);
		del = NULL;
	}
	printf("%d",pHead->_data);
}
//倒置单链表
void ReverseLink(PLinkNode &pHead)
{
   PLinkNode temp = pHead;
   PLinkNode cur = NULL;
   pHead = NULL;
   while(temp)
   {
	   cur = temp->_next;
	   temp->_next = pHead;
	   pHead = temp;
	   temp = cur;
   }
}

//查找链表的中间节点
PLinkNode FindMidNode(PLinkNode pHead)
{
	PLinkNode fast = pHead,slow = pHead;
	assert(pHead);
	assert(pHead->_next);
	assert(pHead->_next->_next);
	while(fast->_next != NULL && fast->_next->_next != NULL)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
	}
	return slow;
	//PLinkNode fast = pHead,slow = pHead;
	//assert(pHead);
	//assert(pHead->_next);
	//while(fast != NULL && fast->_next != NULL)
	//{
	//	slow = slow->_next;0
	//	fast = slow->_next;
	//}
	//return slow;
}