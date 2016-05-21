#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//ztr喜欢幸运数字，他对于幸运数字有两个要求
//1：十进制表示法下只包含4、7
//2：十进制表示法下4和7的数量相等
//比如47, 474477就是
//而4, 744, 467则不是

//现在ztr想知道最小的但不小于n的幸运数字是多少

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