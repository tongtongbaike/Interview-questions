//二叉搜索树建立双向链表。
//改变树的2个分叉的指向。
//根据二叉搜索树的规律，我们需要左中右进行树的遍历。
//然后我们需要保存我们的上一个节点值，以保证双向链表的连接。
//首先进入最左节点，然后连接左节点left，prev的right，然后prev向后移动。
//然后进入当前叉的根节点，再次连接，后判断右树是否存在，然后不断递归重复以上2步。



#include<iostream>
#include<assert.h>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

void BuilderList(BinaryTreeNode* root, BinaryTreeNode **prev)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeNode* cur = root;
	if (cur->_left != NULL)
	{
		BuilderList(cur->_left, prev);
	}
	cur->_left = *prev;
	if (*prev!= NULL)
	{
		(*prev)->_right = cur;
	}	
	(*prev) = cur;
	if (cur->_right != NULL)
	{
		BuilderList(cur->_right, prev);
	}
}

BinaryTreeNode* BSTtoList(BinaryTreeNode* root)
{
	//用来连接节点的前驱节点
	BinaryTreeNode* prev = NULL;
	BuilderList(root,&prev);

	BinaryTreeNode* newList = prev;
	while (newList != NULL && newList->_left != NULL)
	{
		newList = newList->_left;
	}
	return newList;
}

void Test()
{
	BinaryTreeNode* root = new BinaryTreeNode;
	root->_value = 6;
	BinaryTreeNode *left = new BinaryTreeNode;
	BinaryTreeNode *right = new BinaryTreeNode;
	root->_left = left;
	BinaryTreeNode* cur = left;
	cur->_value = 3;
	root->_right = right;
	cur = right;
	cur->_value = 9;
	BinaryTreeNode *left1 = new BinaryTreeNode;
	BinaryTreeNode *right1 = new BinaryTreeNode;
	BinaryTreeNode *left2 = new BinaryTreeNode;
	BinaryTreeNode *right2 = new BinaryTreeNode;
	left->_left = left1;
	cur = left1;
	cur->_value = 1;
	cur->_left = NULL;
	cur->_right = NULL;
	left->_right = right1;
	cur = right1;
	cur->_left = NULL;
	cur->_right = NULL;
	cur->_value = 5;
	right->_left = left2;
	cur = left2;
	cur->_left = NULL;
	cur->_right = NULL;
	cur->_value = 8;
	right->_right = right2;
	cur = right2;
	cur->_left = NULL;
	cur->_right = NULL;
	cur->_value = 11;
	BinaryTreeNode * pHead;
	pHead = BSTtoList(root);
	while (pHead->_right !=NULL)
	{
		printf("%d->", pHead->_value);
		pHead = pHead->_right;
	}
	printf("%d\n", pHead->_value);

	while (pHead)
	{
		if (pHead->_left != NULL)
			printf("%d->", pHead->_value);
		else
			printf("%d\n", pHead->_value);
		pHead = pHead->_left;
	}
}

int main()
{
	Test();
	return 0;
}