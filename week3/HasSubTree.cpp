//Ѱ��һ�����ֵ�������
//�������Ľṹ���£�
//Struct BinaryTreeNode 
//{
//		int m_nvalue;
//      BinaryTreeNode* m_pLeft;
//		BinaryTreeNode* m_pRight;
//}

//��ʵ��������⣬������Ҫ�������Ĳ���������С��Χ�Ľ��п���ȷ�ϡ�
//��С��Χ�Ǵ󲿷������ҵĻ���˼·��
//��Ϊ�ǲ����������������Ǳ������Ľڵ㣬����Ҫȷ������������ڵ㣬
//û������Ҫ������������ѡ��ʹ�õݹ������

//��ʵ�ֽṹ�壬��ֻʵ�ֺ���

#include<iostream>
using namespace std;
//������Ҫ���ҵ�����ÿ���ڵ㡣
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
//������ڵ���ȷ�������±Ƚϲ����������������ҽڵ㣬ֱ������Ϊ�յ������
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