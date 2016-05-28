//��������ĸ���
//1.ÿһ���ڵ���渴��һ���ڵ�β��
//2.���ƽڵ�����ָ��
//3.���Ϊ2������

#include<iostream>
#include<assert.h>
#include<string.h>

using namespace std;

#define LENGTH  10//�洢��������ڵ㣬������鳤��,�ֶ��޸�ʹ����ڽڵ���

typedef int  DataType;
typedef  struct ComplexNode
{
	DataType  _data;//�洢����
	struct  ComplexNode  *_next;//��һ���ڵ��ַ
	struct  ComplexNode  *_random;//���ָ��Ľڵ��ַ
}ComplexNode, *pComplexNode;

pComplexNode  BuyNode(DataType x);//�����ڵ�
//β�岢��ʼ��ʹ�ڵ�����ָ��ָ������ǰһ�����
void Pushback(pComplexNode& pHead, DataType x);
void  Printf(pComplexNode pHead);//��ӡ
void  Destory(pComplexNode&  pHead);//���ٽڵ�
pComplexNode  CopyComplexLink(pComplexNode  pHead);//���Ƹ�������
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
	//�����Ľڵ㸴��һ���������������Ӻ��������
	pComplexNode  source = pHead, tmp = NULL;
	int  count = 1;//������ż��������
	if (pHead == NULL)
	return NULL;
	while (source)
	{
		pComplexNode  temp = source->_next;
		tmp = BuyNode(source->_data);
		source->_next = tmp;//������һ��
		tmp->_next = temp;
		source = tmp->_next;//�������Ƶ��Ǹ�
	}


	//����random
	source = pHead;
	while (source)//��ֵrandom
	{
		if (count % 2 != 0 && source->_random)//�ҵ�������������һ����randomָ������random����һ��

		{
			source->_next->_random = source->_random->_next;
		}
		source = source->_next;
		count++;
	}


	//����
	pComplexNode  target = pHead->_next;//���ж�����һ�����
	source = pHead->_next->_next;
	count = 1;//��ʱsource������λ��
	pComplexNode  targetCur = target, sourceCur = pHead;
	while (source)
	{
		if (count % 2 == 0)//Ŀ���¸�������
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
	sourceCur->_next = NULL;//��֤ԭ�������ɹ�
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


	Printf(pHead);//���һ�ֲ����Ƿ�ı�ԭ������


	Destory(pHead);
	Destory(target);

	system("pause");
	return 0;
}