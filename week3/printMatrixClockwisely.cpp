//
//题目：输入一个矩阵，按照从外向里顺时针的顺序依次打印出每一个数字。例如：
//如果输入一下矩阵：
//1   2   3   4
//5   6   7   8
//9   10  11  12
//13  14  15  16
//则依次打印1，2, 3, 4, 8, 12，16, 15, 14, 13, 9, 5, 6, 7, 11, 10
//对于这个题。首先考虑打印结束的条件，然后考虑如何顺时针打印一圈。
#include<iostream>
using namespace std;

void PrintMatrixInCircle(int **numbers, int cloumns, int rows, int start)
{
	int endX = cloumns - 1 - start;
	int endY = rows - 1 - start;

	//左到右。
	for (int i = start; i <= endX; ++i)
	{
		int number = numbers[start][i];
		cout << number << "  ";
	}

	//上到下
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			cout << number << "  ";
		}
	}

	//右到左

	if (start < endX && start < endY)
	{
		for (int i = endX-1; i >= start; --i)
		{
			int number = numbers[endY][i];
			cout << number << "  ";
		}
	}

	//下到上

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