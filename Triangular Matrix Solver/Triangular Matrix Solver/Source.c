#include<stdio.h>
#include<stdlib.h>
//#include<process.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	double **matrix = (double **)malloc(n * sizeof(double *));
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = (double*)malloc(n*sizeof(double));
		for (int j = 0; j < n; ++j)scanf("%lf", &matrix[i][j]);
	}
	double*y = (double*)malloc(n * sizeof(double));
	double*x = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)scanf("%lf", &y[i]);

	x[n - 1] = y[n - 1] / matrix[n - 1][n - 1];
	for (int i = n-2; i >=0 ;--i)
	{
		double sum = 0;
		for (int j = i+1; j < n; ++j)sum += matrix[i][j] * x[j];
		x[i] = (y[i] - sum) / matrix[i][i];
	}
	for (int i = 0;i < n;++i)printf("%f\n", x[i]);
	//system("pause");
	return 0;
}