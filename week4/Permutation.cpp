//�ַ�������������С�
//��̬�滮


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
			//ȷ�����佻��
			char tmp = *cur;
			*cur = *begin;
			*begin = tmp;
			
			//������С��������
			Permutation(str, begin + 1);
			
			//��ԭ��ǰ�ѽ������С�
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