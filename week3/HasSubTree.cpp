//寻找一棵树种的子树。
//其中树的结构如下：
//Struct BinaryTreeNode 
//{
//		int m_nvalue;
//      BinaryTreeNode* m_pLeft;
//		BinaryTreeNode* m_pRight;
//}

//其实对于这个题，我们需要对于树的操作进行缩小范围的进行控制确认。
//缩小范围是大部分树查找的基本思路。
//因为是查找子树，不仅仅是遍历树的节点，还需要确认子树的其余节点，
//没有特殊要求的情况下我们选择使用递归操作。

//不实现结构体，我只实现函数

#include<iostream>
using namespace std;
//遍历需要查找的树的每个节点。
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (pRoot1->m_nvalue == pRoot2->m_nvalue)
		{
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		}
		if (!result)
		{
			result = HasSubTree(pRoot1->m_pLeft, pRoot2);
		}
		if (!result)
		{
			resule = HasSubTree(pRoot1->m_pRight, pRoot2);
		}
	}
}
//如果根节点正确，则往下比较查找树与子树的左右节点，直到子树为空的情况。
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTree* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->m_nvalue != pRoot2->m_nvalue)
		return false;
	return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft)
		&& DoesTreeHaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}