#include<stdio.h>
#include<math.h>
#include"value.h"

int max(int a, int b)
{
	return (a > b ? a : b);
}

int value(int type, int width, int height, int length)
{
	int typenumber,size=0;
	const int price[] = { 30,10,4,5,3,9 };
	switch (type)
	{
	case 79:
		typenumber = 0;
		break;
	case 47:
		typenumber = 1;
		break;
	case 29:
		typenumber = 2;
		break;
	case 82:
		typenumber = 3;
		break;
	case 26:
		typenumber = 4;
		break;
	case 22:
		typenumber = 5;
		break;

	default:
		return -1;
	}
	if (width <= 0 || height <= 0 || length <= 0)return -2;
	for (int i = 1; i <= width && i <= height && i <= length; ++i)if (width%i == 0 && height%i == 0 && length%i == 0)size = max(size, width/i*height/i*length/i*pow(pow(i, 3), 2));
	return price[typenumber] * size;
}