//
//��Ŀ������һ�����󣬰��մ�������˳ʱ���˳�����δ�ӡ��ÿһ�����֡����磺
//�������һ�¾���
//1   2   3   4
//5   6   7   8
//9   10  11  12
//13  14  15  16
//�����δ�ӡ1��2, 3, 4, 8, 12��16, 15, 14, 13, 9, 5, 6, 7, 11, 10
//��������⡣���ȿ��Ǵ�ӡ������������Ȼ�������˳ʱ���ӡһȦ��
#include<iostream>
using namespace std;

void PrintMatrixInCircle(int **numbers, int cloumns, int rows, int start)
{
	int endX = cloumns - 1 - start;
	int endY = rows - 1 - start;

	//���ҡ�
	for (int i = start; i <= endX; ++i)
	{
		int number = numbers[start][i];
		cout << number << "  ";
	}

	//�ϵ���
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			cout << number << "  ";
		}
	}

	//�ҵ���

	if (start < endX && start < endY)
	{
		for (int i = endX-1; i >= start; --i)
		{
			int number = numbers[endY][i];
			cout << number << "  ";
		}
	}

	//�µ���

	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			int number = numbers[i][start];
			cout << number << "  ";
		}
	}
}

void printMatrixClockwisely(int **numbers, int columns, int rows)
{
	if (numbers == NULL || columns <= 0 || rows <= 0)
		return;

	int start = 0;

	while (columns > start * 2 && rows > start * 2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);
		++start;
	}

	cout << endl;
}



int main()
{
	int one[3] = { 1, 2, 3 };
	int two[3] = { 4, 5, 6 };
	int tree[3] = { 7, 8, 9 };
	int *arry[3] = {one,two,tree};
	printMatrixClockwisely(arry, 3, 3);
	return 0;
}