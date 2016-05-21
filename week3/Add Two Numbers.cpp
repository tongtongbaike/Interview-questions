#include <iostream>

using namespace std;

typedef struct ListNode{
	int _var;
	ListNode *_next;

	ListNode(int var)
		:_var(var)
		, _next(NULL)
	{}
}node, *node_p;

class Solution
{
public:
	node_p add_two_number(ListNode *l1, ListNode *l2)
	{
		node_p NewHead = NULL;
		node_p pa = l1->_next;
		node_p pb = l2->_next;
		int mod = 0;
		while (pa != NULL || pb != NULL){
			int a = 0;
			int b = 0;
			if (pa != NULL)
				a = pa->_var;
			if (pb != NULL)
				b = pb->_var;

			int ret = (a + b + mod) % 10;
			mod = (a + b + mod) / 10;
			node_p tmp = new node(ret);
			tmp->_next = NewHead;
			NewHead = tmp;

			if (pa != NULL)
				pa = pa->_next;
			if (pb != NULL)
				pb = pb->_next;
		}
		if (mod > 0){
			node_p tmp = new node(mod);
			tmp->_next = NewHead;
			NewHead = tmp;
		}

		return NewHead;
	}

	ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1); // 头节点
		int carry = 0;
		ListNode *prev = &dummy;
		for (ListNode *pa = l1, *pb = l2;
			pa != nullptr || pb != nullptr;
			pa = pa == nullptr ? nullptr : pa->_next,
			pb = pb == nullptr ? nullptr : pb->_next,
			prev = prev->_next) {
			const int ai = pa == nullptr ? 0 : pa->_var;
			const int bi = pb == nullptr ? 0 : pb->_var;
			const int value = (ai + bi + carry) % 10;
			carry = (ai + bi + carry) / 10;
			prev->_next = new ListNode(value); // 尾插法
		}
		if (carry > 0)
			prev->_next = new ListNode(carry);
		return dummy._next;
	}
};



int main()
{
	Solution s1;
	node_p l1 = new node(-1);
	node_p pa = l1;
	pa->_next = new node(1);
	pa = pa->_next;
	pa->_next = new node(4);
	pa = pa->_next;
	pa->_next = new node(3);


	node_p l2 = new node(-1);
	node_p pb = l2;
	pb->_next = new node(5);
	pb = pb->_next;
	pb->_next = new node(6);
	pb = pb->_next;
	pb->_next = new node(4);



	node_p ret = s1.add_two_number(l1, l2);
	node_p ret1 = s1.addTwoNumbers1(l1, l2);
	system("pause");
	return 0;
}