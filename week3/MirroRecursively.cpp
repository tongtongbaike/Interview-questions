//�������ľ��񣬺ܼ򵥣���������Ȼ�����������ҽڵ㣬��2����Ϊ�շ��أ�
//Ȼ�󽻲浱ǰ�ڵ�����ҽڵ㣬Ȼ������������ҽڵ㡣��
//���Ľṹ�壺
//struct BinaryTreeNode
//{
//	int m_nvalue;
//	BinaryTreeNode* m_pLefr;
//	BinaryTreeNode* m_pRight;
//
//}

//ʵ�ֺ�����

#include<iostream>
using namespace std;

void MirrRecursively(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL || pNode->m_pLefr == NULL && pNode->m_pRight == NULL)
		return;
	BinaryTreeNode* temp = pRoot->m_pLeft;
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = temp;

	if (pNode->m_pLeft)
		MirrRecursively(pRoot->m_pLeft);
	if (pNode->m_pRight)
		MirrRecursively(pRoot->m_pRight);
}