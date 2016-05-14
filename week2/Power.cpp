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

//��ָoffer�и����˴η�������һ�δη�ֵ��ƽ�������õݹ��������һ�ε�ƽ����
double PowerWithUnsignExponent(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double result = PowerWithUnsignExponent(base, exponent >> 1); //һ��ƽ���൱��ֵ����2�Ρ�
	result *= result;
	
	//Ҫ���ǵ��η���Ϊ������ʱ��������Ҫ�����һ�γ˷���
	if (exponent & 0x1 == 1)
	{
		result *= base;
	}
	return result;
}

//���ڸ�������˵�����ǵıȽ�Ӧ������һ����ֵ��Χ���Ƚ������Ƿ����;
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