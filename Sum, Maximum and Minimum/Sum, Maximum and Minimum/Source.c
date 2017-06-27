#include<stdio.h>
#include<stdlib.h>
//#include<process.h>


int main(void)
{
	int N, m;
	int *number;
	scanf("%d%d", &N, &m);
	number = (int *)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)scanf("%d", &number[i]);
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		int max = 0;
		int min = 0x3f3f3f3f;
		for (int j = 0; j < N; j++)
		{
			if (number[j] % m == i)
			{
				sum += number[j];
				if (number[j] > max)max = number[j];
				if (number[j] < min)min = number[j];
			}
		}
		printf("%d %d %d\n", sum, max, min);
	}
	//system("pause");
	return 0;
}