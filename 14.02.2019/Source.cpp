#include<iostream>
#include<iomanip>
#include<locale.h>
#include<Windows.h>

using namespace std;

int A[10]/*[5]*/;
const int n = 10, m = 5;

void Reverse(int a[], int low, int high)
{
	if (low > high)
	{
		return;
	}
	swap(a[low], a[high]);
	Reverse(a, low + 1, high - 1);
}

void FillArray2()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{

			A[i][j] = 0 + rand() % 2;

		}
	}
}

void FillArray1()
{
	for (size_t i = 0; i < n; i++)
	{
		A[i]= 0 + rand() % 100;
	}
}

void PrintArray1()
{
	for (size_t i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}


void PrintArray()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{

			cout << A[i][j] << " ";

		}
		cout << endl;
	}
}

int SumArray(int A[], int a, int n)
{
	if (n == a +1)
	{
		return A[n - 1];
	}
	return A[n - 1] + SumArray(A,a, n - 1);
}

int Minimal100(int A[], int n)
{
	int b = 0;
	int a = 0;
	int B[50];
	if (n == 0)
	{
		return A[n - 1];
	}
	B[a] = SumArray(A, b, b + 2);
	a++; b++;
	MinNumber(B, n);
	return Minimal100(A, n - 1);
}

int MinNumber(int A[], int n)
{
	int index;
	static int Min = A[0];
	if (n == 1)
	{
		return A[n - 1];
	}
	if (Min > A[n - 1])
		Min = A[n - 1];

	MinNumber(A, n - 1);
	return Min;


}

int Cells( int i, int j)
{
	static int sum = 0;
	if (i >= 0 && i <n && j>=0 && j < m)
	{
		if (A[i][j] == 1)
		{
			A[i][j] = 2;
			sum++;

			if (A[i + 1][j - 1] == 1) Cells(i + 1, j - 1);
			if (A[i + 1][j ] == 1) Cells(i + 1, j);
			if (A[i + 1][j + 1] == 1) Cells(i + 1, j + 1);
			if (A[i - 1][j + 1] == 1) Cells(i - 1, j + 1);
			if (A[i - 1][j] == 1) Cells(i - 1, j + 1);
			if (A[i - 1][j - 1] == 1) Cells(i - 1, j - 1);
			if (A[i ][j - 1] == 1) Cells(i, j - 1);
			if (A[i][j + 1] == 1) Cells(i, j + 1);
		}

	}
	return sum;
}

bool Maze(int i, int j)
{
	int flag = 0;

	if (i == n - 1 && j == m - 1 && A[i][j] == 1)
	{
		flag = 1;
	}

	if (i >= 0 && i < n && j >= 0 && j < m)
	{
		if (A[i][j] == 1)
		{
			A[i][j] = 2;

			if (A[i + 1][j] == 1) Maze(i + 1, j);
			if (A[i - 1][j] == 1) Maze(i - 1, j + 1);
			if (A[i][j - 1] == 1) Maze(i, j - 1);
			if (A[i][j + 1] == 1) Maze(i, j + 1);

			if (A[i][j] == 2 && A[i][j] == A[n - 1][m - 1])
			{
				flag = 1;
			}

		}

	}
	if (flag == 1)
	{
		return 1;
	}
	else return 0;
}



int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int flag;
	int i, j;
	do
	{
		FillArray();
		PrintArray();
		cin >> i >> j;
		cout << Maze(i, j) << endl;

		cout << "Continue?1/0";
		cin >> flag;

	} while (flag == 1);

}
