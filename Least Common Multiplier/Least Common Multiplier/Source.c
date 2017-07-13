#include<stdio.h>
//#include<process.h>

int gcd(int x, int y)
{
	int a = x, b = y;
	if (b > a)//let a bigger than b
	{
		int temp;
		temp = b;
		b = a;
		a = temp;
	}
	while (b!=0)
	{
		int temp;
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int main(void)
{
	int number = 0;
	int input;
	int stored=1;
	//printf("%d", gcd(60, 120));
	while (scanf("%d", &input) == 1)
	{
		stored = stored*input / gcd(input, stored);
	}
	printf("%d", stored);
	//system("pause");
	return 0;
}