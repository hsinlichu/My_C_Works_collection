#include<stdio.h>
#include"intersection.h"
#include<stdlib.h>
#include<process.h>

int main(void)
{
	int matrix[100][100];
	int result[4];
	for (int i = 0; i < 100; ++i)for (int j = 0;j < 100;++j)scanf("%d", &matrix[i][j]);
	intersection(matrix, result);
	for (int i = 0; i < 4; ++i)printf("%d\n", result[i]);
	system("pause");
	return 0;
}