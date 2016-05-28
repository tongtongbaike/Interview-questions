//字符串所有组合序列。
//动态规划


#include<iostream>
using namespace std;

void Permutation(char *str, char *begin)
{
	if (*begin == '\0')
	{
		cout << str << endl;
	}
	else{
		for (char *cur = begin; *cur != '\0'; ++cur)
		{
			//确定区间交换
			char tmp = *cur;
			*cur = *begin;
			*begin = tmp;
			
			//不断缩小交换区间
			Permutation(str, begin + 1);
			
			//还原当前已交换序列。
			tmp = *cur;
			*cur = *begin;
			*begin = tmp;
		}
	}
}

void Permutation_Non(char* str)
{
	if (str == NULL)
	{
		return;
	}

	Permutation(str, str);

}

int main()
{
	char str [4]= "abc";
	Permutation_Non(str);
	return 0;
}