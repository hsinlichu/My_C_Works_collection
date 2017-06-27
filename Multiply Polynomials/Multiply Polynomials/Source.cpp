#include<stdio.h>
//#include<process.h>
using namespace std;

int main()
{
	int m, n;
	scanf("%d", &m);
	int *poly1;
	poly1 = new int[m];
	for (int i = m - 1; i >= 0; i--)scanf("%d", &poly1[i]);
	scanf("%d", &n);
	int *poly2;
	poly2 = new int[n];
	for (int i = n - 1; i >= 0; i--)scanf("%d", &poly2[i]);
	int *sum;
	sum = new int[m+n-1];
	for (int i = 0; i < m + n - 1; i++)sum[i] = 0;
	for (int i = 0; i < m; i++)for (int j = 0;j < n;j++)sum[i + j] += poly1[i] * poly2[j];
	for (int i = m + n - 2; i >= 0; i--)
	{
		if(i!=0)printf("%d ", sum[i]);// printf((i==0)?"%d":"%d ", c[i]); ¶W²r!!!!!!!!!!!!!!!!
		else printf("%d", sum[i]);
	}
	//system("pause");
	return 0;
}