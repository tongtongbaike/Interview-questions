#include<iostream>

using namespace std;

//百度有一道面试题就是小姚同学去参观公司，然后每次上一阶，2阶，3阶。台阶一共36阶，问有多少种跳法。
//其实就是这个题的变种，只需要考虑3种跳法的计算。
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