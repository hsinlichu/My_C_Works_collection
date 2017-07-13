#include<stdio.h>
//#include<process.h>
#define pi 3.1415926
int main(void)
{
	double a, b, c,sum=0.0;
	scanf("%lf%lf%lf", &a, &b, &c);
	sum += pi*c*c*3/4;
	if (c > b)sum += pi*(c - b)*(c - b) / 4;
	if (c > a)sum += pi*(c - a)*(c - a) / 4;
	printf("%f\n", sum);
	//system("pause");
	return 0;
}