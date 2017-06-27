#include<stdio.h>
//#include<process.h>
#include<vector>
using namespace std;

int main()
{
	int size;
	scanf("%d", &size);
	int *matrix;
	vector<int>odd;
	vector<int>even;
	matrix = new int[size];
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &matrix[i]);
		if (matrix[i] % 2 == 0)even.push_back(matrix[i]);
		else odd.push_back(matrix[i]);
	}

	for (vector<int>::iterator i=odd.begin(); i <odd.end(); i++)
	{
		if (i != odd.end()-1)printf("%d ", *i);
		else printf("%d\n", *i);
	}
	for (vector<int>::iterator i = even.begin(); i <even.end(); i++)
	{
		if (i != even.end() - 1)printf("%d ", *i);
		else printf("%d\n", *i);
	}

	//system("pause");
	return 0;
}