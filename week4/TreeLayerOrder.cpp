//二叉树的层次遍历。
//我们需要一个辅助队列的帮助，在队列中，是先进先出。
//首先打印了当前值，然后左右值压入队列，然后popfront。
//就相当于当前层存储，然后下一层，在下一层。

#include<iostream>
#include<queue>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

void LayerOrder(BinaryTreeNode *root)
{
		queue<BinaryTreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			if (q.front())
			{
				cout << q.front()->_value << "  ";
				if (q.front()->_left)
					q.push(q.front()->_left);
				if (q.front()->_right)
					q.push(q.front()->_right);
				q.pop();
			}
		}
		cout << endl;
}

int main()
{
	BinaryTreeNode* root = new BinaryTreeNode;
	root->_value = 1;
	BinaryTreeNode *left = new BinaryTreeNode;
	BinaryTreeNode *right = new BinaryTreeNode;
	root->_left = left;
	BinaryTreeNode* cur = left;
	cur->_value = 2;
	root->_right = right;
	cur = right;
	cur->_value = 3;
	BinaryTreeNode *left1 = new BinaryTreeNode;
	BinaryTreeNode *right1 = new BinaryTreeNode;
	BinaryTreeNode *left2 = new BinaryTreeNode;
	BinaryTreeNode *right2 = new BinaryTreeNode;
	left->_left = left1;
	cur = left1;
	cur->_value = 4;
	cur->_left = NULL;
	cur->_right = NULL;
	left->_right = right1;
	cur = right1;
	cur->_left = NULL;
	cur->_right = NULL;
	cur->_value = 5;
	right->_left= left2;
	cur = left2;
	cur->_left = NULL;
	cur->_right = NULL;
	cur->_value = 6;
	right->_right = right2;
	cur = right2;
	cur->_left = NULL;
	cur->_right = NULL;
	cur->_value = 7;
	LayerOrder(root);
	return 0;
}