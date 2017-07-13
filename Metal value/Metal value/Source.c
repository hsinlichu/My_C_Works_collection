#include<stdio.h>
#include<process.h>
#include"value.h"

int main(void)
{
	int type, w, h, l;
	scanf("%d%d%d%d", &type, &w, &h, &l);
	printf("%d", value(type, w, h, l));


	system("pause");
	return 0;
}