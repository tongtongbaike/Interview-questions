#include<iostream>
using namespace std;

//11 2bit 1011
//��1���൱�����ұ�1������1��֮��Ľ���0 . 1�任
//���뱾�������룬��������1������1����Ľ���λȫ����Ϊ0;

int BitOneCount(int number)
{
	int count = 0;
	while (number)
	{
		++count;
		number = number &(number - 1);
	}
	return count;
}


int main()
{
	cout << BitOneCount(11)<<endl;
	return 0;
}