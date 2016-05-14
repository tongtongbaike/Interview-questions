#include<iostream>
#include<string.h>
using namespace std;


//��ӡһ��nλ������ʵ������Ҫ���ǵ����Ľ���ֵ���⡣
//��������ȫ���еݹ�ⷨ�������.

void PrintNumber(char *number)
{
	bool flag = true;
	int length = strlen(number);

	for (int i = 0; i < length; ++i)
	{
		if (flag && number[i] != '0')
		{
			flag = false;
		}
		if (!flag)
		{
			printf("%c", number[i]);
		}
	}
	printf("\n");
}


void PrintMaxToDigit(char *number, int length, int index)
{
	if (index == length)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		/*number[index+1] = i + '0';*/
		number[index] = i + '0';
		PrintMaxToDigit(number, length, index + 1);
	}
}

void PrintMax(int n)
{
	if (n < 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';
	/*for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		PrintMaxToDigit(number, n, 0);
	}*/
	PrintMaxToDigit(number, n, 0);
	delete[] number;
}

//�����ַ���ģ�����Ľ�λ����
bool Income(char *number)
{
	bool flag = false;
	int over = 0;
	int length = strlen(number);
	for (int i = length - 1; i >= 0; --i)
	{
		int sum = number[i] - '0' + over;
		//����ǰλ�������λʱ����1��ʼ���.���λ����+1
		if (i == length - 1)
			++sum;
		if (sum >= 10)
		{
			if (i == 0)
			{
				flag = true;
			}
			else
			{
				sum -= 10;
				number[i] = sum + '0';
				over = 1;
			}
		}
		else
		{
			number[i] = sum + '0';
			break;
		}
	}

	return flag;
}


void PrintNumberToString(int n)
{
	if (n < 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Income(number))
	{
		PrintNumber(number);
	}
	delete[] number;
}

int main()
{
	//PrintMax(4);
	PrintNumberToString(3);
	return 0;
}