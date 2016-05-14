#include "SLinkNode.h"

void Test()
{
	PLinkNode seq;
	InitList(seq);
	PushBack(seq,1);
	PushBack(seq,2);
	PushBack(seq,3);
	PrintList(seq);

	PopBack(seq);
	PopBack(seq);
	PopBack(seq);
	PopBack(seq);
	PrintList(seq);

	//DestoryLink(seq);
	//PrintList(seq);
}

void Test2()
{
	PLinkNode seq;
	InitList(seq);
	PushFront(seq,1);
	PushFront(seq,2);
	PushFront(seq,3);
	PushFront(seq,4);
	PushFront(seq,5);
	PrintList(seq);

	PopFront(seq);
	PopFront(seq);
	PopFront(seq);
	PopFront(seq);
	PopFront(seq);
	PopFront(seq);
	PrintList(seq);
}

void Test3()
{
	PLinkNode seq;
	PLinkNode ret;
	InitList(seq);
	PushBack(seq,1);
	PushBack(seq,2);
	PushBack(seq,3);
	PrintList(seq);

	ret = Find(seq,3);
	Insert(ret,4);
	PrintList(seq);

	Erase(seq,ret);
	PrintList(seq);

	ret = Find(seq,2);
	EraseNoHead(ret);
	PrintList(seq);
	DestoryLink(seq);
}

void Test4()
{
	PLinkNode seq;
	InitList(seq);
	PushFront(seq,1);
	PushFront(seq,2);
	PushFront(seq,3);
	PushFront(seq,4);
	PushFront(seq,5);
	PushFront(seq,7);
	PushFront(seq,5);
	PushFront(seq,8);
	PushFront(seq,5);
	PushFront(seq,9);
	PushFront(seq,5);
	PrintList(seq);

	Remove(seq,5);
	PrintList(seq);

	RemoveAll(seq,5);
	DestoryLink(seq);
}

void Test5()
{
	PLinkNode seqOne,seqTwo;
	InitList(seqOne);
	PushBack(seqOne,1);
	PushBack(seqOne,4);
	PushBack(seqOne,7);
	PushBack(seqOne,9);
	PushBack(seqOne,11);
	PushBack(seqOne,13);
	PrintList(seqOne);

	InitList(seqTwo);
	PushBack(seqTwo,2);
	PushBack(seqTwo,3);
	PushBack(seqTwo,4);
	PushBack(seqTwo,6);
	PushBack(seqTwo,9);
	PushBack(seqTwo,10);
	PushBack(seqTwo,11);
	PrintList(seqTwo);

	FindEqualData(seqOne,seqTwo);
	DestoryLink(seqOne);
	DestoryLink(seqTwo);
}

void Test6()
{
	PLinkNode seqOne,seqIndex;
	InitList(seqOne);
	InitList(seqIndex);
	PushBack(seqOne,1);
	PushBack(seqOne,4);
	PushBack(seqOne,7);
	PushBack(seqOne,9);
	PushBack(seqOne,11);
	PushBack(seqOne,13);
	seqIndex = seqOne;

	/*
	PrintList(seqOne);
	PrintFailToHead(seqOne);*/
	while(seqIndex->_next != NULL)
	{
		seqIndex = seqIndex->_next;
	}
	seqIndex->_next = seqOne;
	JosephRing(seqOne,3);

}

void Test7()
{
	PLinkNode seq;
	PLinkNode seqMid;
	InitList(seq);
	PushFront(seq,1);
	PushFront(seq,2);
	PushFront(seq,3);
	PushFront(seq,4);
	PushFront(seq,5);
	PushFront(seq,7);
	PushFront(seq,5);
	PushFront(seq,8);
	PushFront(seq,5);
	PushFront(seq,9);
	PushFront(seq,5);
	PrintList(seq);

	ReverseLink(seq);
	PrintList(seq);

	seqMid = FindMidNode(seq);
	printf("%d",seqMid->_data);
}
int main()
{
	Test7();
	return 0;

}