#include<iostream>
using namespace std;

double Power(double number,int expoent)
{
	if (Equals(number, 0.0) && expoent < 0)
	{
		return 0.0;
	}
	unsigned int absExpoent = (unsigned int)expoent;
	if (expoent < 0)
	{
		absExpoent = -expoent;
	}
	/*double result = 1.0;
	if (expoent == 0)
		return 1;
	
	if (expoent == 1)
		return number;

	for (int i = 1; i <= expoent; ++i)
	{
		result *= number;
	}
*/
	double result = PowerWithUnsignExponent(number, absexpoent);
	if (expoent < 0)
		result = 1.0 / result;

	return result;
}

//剑指offer中给出了次方等于上一次次方值的平方，利用递归来求解这一次的平方；
double PowerWithUnsignExponent(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double result = PowerWithUnsignExponent(base, exponent >> 1); //一次平方相当于值乘以2次。
	result *= result;
	
	//要考虑当次方数为奇数的时候，我们需要多进行一次乘法。
	if (exponent & 0x1 == 1)
	{
		result *= base;
	}
	return result;
}

//对于浮点数来说，我们的比较应该利用一个差值范围来比较他们是否相等;
bool Equals(int number1, int number2)
{
	if (number1 - number2 < 0.0000001
		&& number2 - number1 > -0.0000001)
		return true;
	else
		return false;
}

int main()
{
	cout << Power(2, 5);
	return 0;
}