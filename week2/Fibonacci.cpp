#include<iostream>

using namespace std;

//�ٶ���һ�����������СҦͬѧȥ�ι۹�˾��Ȼ��ÿ����һ�ף�2�ף�3�ס�̨��һ��36�ף����ж�����������
//��ʵ���������ı��֣�ֻ��Ҫ����3�������ļ��㡣
long long Fibonacci(unsigned int number)
{
	if (number <= 0)
	{
		return 0;
	}
	if (number == 1)
		return 1;

	return Fibonacci(number - 1) + Fibonacci(number - 2);

}

long long Fibonacci_Non(unsigned int number)
{
	if (number <= 0)
		return 0;
	if (number == 1)
		return 1;
	int FibonacciOne = 1;
	int FibonacciTwo = 0;
	int FibonacciSum = 0;
	for (int i = 2; i <= number; ++i)
	{
		FibonacciSum = FibonacciOne + FibonacciTwo;
		FibonacciTwo = FibonacciOne;
		FibonacciOne = FibonacciSum;
	}

	return FibonacciSum;

}

int main()
{
	cout << Fibonacci(5);
	cout << Fibonacci_Non(5);
	return 0;
}