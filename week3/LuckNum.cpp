#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//ztrϲ���������֣���������������������Ҫ��
//1��ʮ���Ʊ�ʾ����ֻ����4��7
//2��ʮ���Ʊ�ʾ����4��7���������
//����47, 474477����
//��4, 744, 467����

//����ztr��֪����С�ĵ���С��n�����������Ƕ���

#include <iostream>

class LuckNum
{
public:
	int Minnum(int n)
	{
		int arry[2] = {0};
		if (n < 47)
		{
			return 47;
		}
		int temp = n;
		for (int i = temp;; ++i)
		{
			temp = i;
			while (temp != 0)
			{
				if (temp % 10 == 4)
				{
					++arry[0];
				}
				if (temp % 10 == 7)
				{
					++arry[1];
				}
				temp /= 10;
			}
			if (arry[0] == arry[1])
			{
				return i;
			}
		}
	}

	int Minum_op(int n)
	{
		if (n < 47)
			n = 47;
		vector<int> a;
		a.push_back(4);
		a.push_back(7);
		while (1){
			sort(a.begin(), a.end());
			while (1){
				int ret = a[0];
				for (int i = 1; i < a.size(); ++i){
					ret = ret * 10 + a[i];
				}
				if (ret >= n){
					return ret;
				}
				if (false == next_permutation(a.begin(), a.end()))
					break;
			}
			a.push_back(4);
			a.push_back(7);
		}
	}
};