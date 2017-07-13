#include "max.h"
int max(int array[5][5]) {
	int *max = array;
	for (int i = 0; i < 5; ++i)for (int j = 0;j < 5;++j)if (array[i][j] > *max)max = &array[i][j];
	return *max;
}

/*int max(int a[5][5]) {
    int i;
    int max = -1;
    for(i=0; i<5*5; i++) max = (max < a[i/5][i%5])? a[i/5][i%5] :max;
    return max;
	}*/