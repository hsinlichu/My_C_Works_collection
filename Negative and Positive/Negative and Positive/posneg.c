#include "posneg.h"
void posneg(int array[5][5], int result[2])
{
	result[0] = result[1] = 0;
	for (int i = 0; i < 25; ++i)
	{
		if (array[i / 5][i % 5] > 0)result[1]++;
		if (array[i / 5][i % 5] < 0)result[0]++;
	}
}