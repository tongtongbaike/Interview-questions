#pragma once
#include<stdio.h>

typedef int DataType;

typedef struct LinkNode
{
	DataType _data;
	struct LinkNode *_next;
}LinkNode,*PLinkNode;

void InitList(PLinkNode &pHead);
void PrintList(PLinkNode pHead);
int GetListLength(PLinkNode pHead);
void DestoryLink(PLinkNode &pHead);
void PushBack(PLinkNode &pHead,DataType x);
void PopBack(PLinkNode &pHead);
void PushFront(PLinkNode &pHead,DataType x);
void PopFront(PLinkNode &pHead);

PLinkNode Find(PLinkNode pHead,DataType x);
void Insert(PLinkNode pos,DataType x);
void EraseNoHead(PLinkNode pos);
void Erase(PLinkNode &pHead,PLinkNode pos);
void Remove(PLinkNode &pHead,DataType x);
void RemoveAll(PLinkNode &pHead,DataType x);
void FindEqualData(PLinkNode oneHead,PLinkNode twoHead);
void PrintFailToHead(PLinkNode pHead);
void JosephRing(PLinkNode &pHead,DataType x);
void ReverseLink(PLinkNode &pHead);
PLinkNode FindMidNode(PLinkNode pHead);