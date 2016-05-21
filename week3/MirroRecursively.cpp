//二叉树的镜像，很简单，遍历树，然后考虑树的左右节点，当2个都为空返回，
//然后交叉当前节点的左右节点，然后进入他的左右节点。、
//树的结构体：
//struct BinaryTreeNode
//{
//	int m_nvalue;
//	BinaryTreeNode* m_pLefr;
//	BinaryTreeNode* m_pRight;
//
//}

//实现函数：

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