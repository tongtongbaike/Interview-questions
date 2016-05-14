#include<iostream>
using namespace std;

//11 2bit 1011
//减1后相当于最右边1（包括1）之后的进行0 . 1变换
//后与本身数相与，将把最右1（包括1）后的进制位全部置为0;

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