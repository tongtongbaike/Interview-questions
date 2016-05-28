//ǰ���������
//Ѱ��·����Ȼ��������һ������ֵ��Ȼ�����ҷ��ʣ���Ҷ�ӽڵ�󷵻ز��Ҽ�ȥ��
//���ε��Թ����⣬Ȼ��ȷ����ջ��Ҫ��ȥ����ֵ��
//ֵ��Ȳ�������Ҷ�ӽڵ�ʹ�ӡ·����

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

static bool flag = false;

void FindPath(BinaryTreeNode* root, int number, vector<int> &PathStack, int sumNumber)
{
	assert(root);
	sumNumber += root->_value;
	PathStack.push_back(root->_value);
	bool isLeaf = (root->_left == NULL) && (root->_right == NULL);
	if (sumNumber == number && isLeaf)
	{
		flag = true;
		printf("Path is");
		vector<int>::iterator iter= PathStack.begin();
		for (; iter != PathStack.end(); ++iter)
		{
			printf("%d\t", *iter);
		}
		cout << endl;
	}

	if (root->_left != NULL)
	{
		FindPath(root->_left, number, PathStack, sumNumber);
	}

	if (root->_right != NULL)
	{
		FindPath(root->_right, number, PathStack, sumNumber);
	}

	sumNumber -= root->_value;
	PathStack.pop_back();
	if (PathStack.empty() && !flag)
	{
		printf("not found path \n");
	}
}


void FindPath_Non(BinaryTreeNode* root, int number)
{
	assert(root);
	std::vector<int> PathStack;
	int sumNumber = 0;
	FindPath(root,number, PathStack, sumNumber);
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
	right->_left = left2;
	cur = left2;
	cur->_left = NULL;
	cur->_right = NULL;
	cur->_value = 6;
	right->_right = right2;
	cur = right2;
	cur->_left = NULL;
	cur->_right = NULL;
	cur->_value = 7;
	FindPath_Non(root, 9);

	return 0;
}