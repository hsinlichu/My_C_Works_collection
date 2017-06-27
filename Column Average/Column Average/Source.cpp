#include<stdio.h>
//#include<process.h>
using namespace std;

int main()
{
	int r, c;
	scanf("%d%d", &r, &c);
	int **matrix;
	matrix = new int*[r];
	for (int i = 0; i < r; i++)
	{
		matrix[i] = new int[c];
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < c; i++)
	{
		int sum = 0;
		for (int j = 0;j < r;j++)sum += matrix[j][i];
		printf("%d\n", sum / r);
	}
	//system("pause");
	return 0;
}