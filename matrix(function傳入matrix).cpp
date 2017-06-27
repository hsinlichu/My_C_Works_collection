#include<iostream>
#include<process.h>
using namespace std;


void matricOutput(float **, unsigned int, unsigned int);
void matricInput(float **, unsigned int, unsigned int);
void matricMemoryFree(float **, unsigned int, unsigned int);
void matricAdd(float **,float **,float **, unsigned int, unsigned int);


int main()
{
	cout << "Please enter the size of metric:(ex: 3*5: 3 5)\n";
	unsigned int row, col;
	cin >> row >> col;
	float **A = new float*[row];
	for (rsize_t i = 0;i < row;i++)
	{
		A[i] = new float[col];
	} 


	cout << "Please enter the number of metric A for each row in order:\n";
	matricInput(A, row, col);

	float **B = new float*[row];
	for (rsize_t i = 0;i < row;i++)
	{
		B[i] = new float[col];
	}

	cout << "Please enter the number of metric B for each row in order:\n";
	matricInput(B, row, col);

	cout << "Your input A=\n";
	matricOutput(A, row, col);

	cout << "Your input B=\n";
	matricOutput(B, row, col);

	float **C = new float*[row];
	for (rsize_t i = 0;i < row;i++)
	{
		C[i] = new float[col];
	}

	cout << "The answer C=\n";
	matricAdd(A,B,C,row,col);
	for (size_t i = 0;i < row;i++)
	{
		for (size_t j = 0;j<col;j++)
		{
			if (j == col - 1)cout << C[i][j] << endl;
			else cout << C[i][j] << " ";
		}
	}
	matricMemoryFree(A, row, col);
	matricMemoryFree(B, row, col);
	matricMemoryFree(C, row, col);

	system("pause");
	return 0;
}


void matricOutput(float **a, unsigned int row, unsigned int col)
{
	for (size_t i = 0;i < row;i++)
	{
		for (size_t j = 0;j<col;j++)
		{
			if (j == col - 1)cout << a[i][j] << endl;
			else cout << a[i][j] << " ";
		}
	}

}
void matricInput(float **a, unsigned int row, unsigned int col)
{
	for (size_t i = 0;i < row;i++)
	{
		for (size_t j = 0;j<col;j++)
		{
			cin >> a[i][j];
		}
	}
}
void matricMemoryFree(float **a, unsigned int row, unsigned int col)
{
	for(size_t i=0;i<row;i++)
	{
		delete[] a[i];
	}
	delete[] a;
}

void matricAdd(float **a,float **b,float **c, unsigned int row, unsigned int col)
{
	for (size_t i = 0;i < row;i++)
	{
		for (size_t j = 0;j<col;j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}


