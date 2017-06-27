#include<stdio.h>
//#include<process.h>
using namespace std;

int main()
{
	int size;
	scanf("%d", &size);
	int *matrix;
	matrix = new int[size];
	for (int i = 0; i < size; i++)scanf("%d", &matrix[i]);
	for (int i = size - 1; i >= 0; i--)
	{
		if(i!=0)printf("%d ", matrix[i]);
		else printf("%d", matrix[i]);
	}

	//system("pause");
	return 0;
}