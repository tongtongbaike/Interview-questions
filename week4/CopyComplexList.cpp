//复杂链表的复制
//1.每一个节点后面复制一个节点尾随
//2.复制节点的随机指向。
//3.拆分为2个链表。

#include<iostream>
#include<assert.h>
#include<string.h>

using namespace std;

#define LENGTH  10//存储数据随机节点，设个数组长度,手动修改使其大于节点数

typedef int  DataType;
typedef  struct ComplexNode
{
	DataType  _data;//存储数据
	struct  ComplexNode  *_next;//下一个节点地址
	struct  ComplexNode  *_random;//随机指向的节点地址
}ComplexNode, *pComplexNode;

pComplexNode  BuyNode(DataType x);//创建节点
//尾插并初始化使节点的随机指针指向它的前一个结点
void Pushback(pComplexNode& pHead, DataType x);
void  Printf(pComplexNode pHead);//打印
void  Destory(pComplexNode&  pHead);//销毁节点
pComplexNode  CopyComplexLink(pComplexNode  pHead);//复制复杂链表
pComplexNode  BuyNode(DataType x)
{
	pComplexNode tmp = NULL;
	tmp = (pComplexNode)malloc(sizeof(ComplexNode));
	tmp->_data = x;
	tmp->_next = NULL;
	tmp->_random = NULL;
	return tmp;
}
void Pushback(pComplexNode& pHead, DataType x)
{
	pComplexNode  cur = pHead, pre = NULL;
	if (pHead == NULL)
	{
		pHead = BuyNode(x);
		pHead->_random = NULL;
	}
	else
	{
		while (cur->_next)
		{
			pre = cur;
			cur = cur->_next;
		}
		cur->_next = BuyNode(x);
		cur->_random = pre;
		cur->_next->_random = cur;
	}
}
void  Printf(pComplexNode pHead)
{
	while (pHead)
	{
		printf("%d", pHead->_data);
		if (pHead->_random)
		{
			printf(" random:%d  ->", pHead->_random->_data);
		}
		else
			printf(" random:NULL  ->");
		pHead = pHead->_next;
	}
	printf("NULL\n");
}
void  Destory(pComplexNode&  pHead)
{
	pComplexNode del = NULL;
	if (pHead == NULL)
		return;
	while (pHead)
	{
		del = pHead;
		pHead = pHead->_next;
		free(del);
	}
}

pComplexNode  CopyComplexList(pComplexNode  pHead)
{
	//将它的节点复制一份连接起来，连接后的新链表
	pComplexNode  source = pHead, tmp = NULL;
	int  count = 1;//控制奇偶，最后分离
	if (pHead == NULL)
	return NULL;
	while (source)
	{
		pComplexNode  temp = source->_next;
		tmp = BuyNode(source->_data);
		source->_next = tmp;//连接在一起
		tmp->_next = temp;
		source = tmp->_next;//跳过复制的那个
	}


	//复制random
	source = pHead;
	while (source)//赋值random
	{
		if (count % 2 != 0 && source->_random)//找到奇数，让它下一个的random指向它的random的下一个

		{
			source->_next->_random = source->_random->_next;
		}
		source = source->_next;
		count++;
	}


	//分离
	pComplexNode  target = pHead->_next;//已判定至少一个结点
	source = pHead->_next->_next;
	count = 1;//此时source是奇数位置
	pComplexNode  targetCur = target, sourceCur = pHead;
	while (source)
	{
		if (count % 2 == 0)//目标新复制链表
		{
			targetCur->_next = source;
			targetCur = targetCur->_next;
		}
		else
		{
			sourceCur->_next = source;
			sourceCur = sourceCur->_next;
		}
		source = source->_next;
		count++;
	}
	sourceCur->_next = NULL;//保证原链表分离成功
	return  target;
}


int main()
{
	pComplexNode pHead = NULL, target = NULL;
	Pushback(pHead, 1);
	Pushback(pHead, 2);
	Pushback(pHead, 3);
	Pushback(pHead, 4);
	Pushback(pHead, 5);
	Pushback(pHead, 6);
	Printf(pHead);


	target = CopyComplexList(pHead);
	Printf(target);


	Printf(pHead);//最后一种测试是否改变原来链表


	Destory(pHead);
	Destory(target);

	system("pause");
	return 0;
}