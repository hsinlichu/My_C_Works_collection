#include<stdio.h>
//#include<process.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int inputx, inputy;
	vector<int>x;
	vector<int>y;
	while (scanf("%d",&inputx)==1)//²×¤î¿é¤Jctrl+z  or scanf("%d%d", &x, &y) != EOF
	{
		x.push_back(inputx);
		scanf("%d", &inputy);
		y.push_back(inputy);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int area;
	area = (*(x.end() - 1) - *(x.begin() ))*(*(y.end() - 1) - *(y.begin()));
	printf("%d", area);
	/*
	for (vector<int>::iterator i = x.begin(); i < x.end(); i++)
	{
		printf("%d ", *i);
	}
	*/



	//system("pause");
	return 0;
}