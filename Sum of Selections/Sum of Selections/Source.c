#include<stdio.h>
//#include<process.h>

int factorial(int number,int n)
{
	int sum=1;
	for (int i = number; i > 0,n > 0; i--,n--)sum *= i;
	return sum;
}

int sum(int m, int n)
{
	int totalway = 0;
	for (int i = 0; i <= n; ++i)
	{
		totalway += factorial(m,i) / factorial(i,i);
		//printf("%d/%d %d\n", factorial(m, i), factorial(i, i),totalway);
	}
	return totalway;
}

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d", sum(m, n));
	//system("pause");
	return 0;
}