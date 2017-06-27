#include<stdio.h>
//#include<process.h>
using namespace std;

int main()
{
	int size;
	long int number;
	scanf("%d", &size);
	int *matrix, *remainder;
	matrix = new int[size];
	
	for (int i = 0; i < size; i++)scanf("%d", &matrix[i]);
	scanf("%d", &number);
	remainder = new int[number];
	for (int i = 0; i < number; i++)remainder[i]=0;
	for (int i = 0; i < size; i++)remainder[matrix[i] % number]++;
	for (int i = 0; i < number; i++)printf("%d\n", remainder[i]);

	//system("pause");
	return 0;
}