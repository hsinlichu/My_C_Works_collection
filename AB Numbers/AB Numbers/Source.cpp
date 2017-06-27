#include<stdio.h>
//#include<process.h>
using namespace std;

int main()
{
	char a[5], b[5];
	int A = 0, B = 0;
	scanf("%s%s", &a, &b);
	for (int i=0; i < 4; i++)
	{
		//printf("counter:%d\n", i);
		//printf("%d,%d\n", a[i], b[i]);
		if (a[i] == b[i])
		{
			//printf("i:%d A\n", i);
			A++;
		}
		for (int j = 0; j <4 ; j++)
		{
			if ((a[i] == b[j])&&(j!=i))
			{
				//printf("i:%d,j:%d B\n", i,j);
				B++;
			}
		}
	}
	printf("%dA%dB", A, B);
	//system("pause");
	return 0;
}