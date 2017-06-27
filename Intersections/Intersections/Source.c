#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int number;
	while (scanf("%d",&number)==1)
	{
		number += 2;
		int **matrix;
		matrix = (int **)malloc(number * sizeof(int));
		for (int i = 0; i < number; i++)
		{
			matrix[i] = (int *)malloc(number * sizeof(int));
			
			for (int j = 0; j < number ; j++)
			{
				if (i == 0 || i == number-1 || j == 0 || j == number-1)matrix[i][j] = 0;
				else scanf("%d", &matrix[i][j]);
			}
		}
		//for (int i = 0; i < number; i++)for (int j = 0;j < number;j++)printf(j == number - 1 ? "%d\n" : "%d ", matrix[i][j]);
		
		int intersection = 0, Tjunctions = 0, turns = 0, deadends = 0;
		const int dx[] = {0,1,0,-1};//上右下左
		const int dy[] = {-1,0,1,0};
		const int  t[] = { 1,10,1,10};
		for (int i = 1; i < number-1; i++)
		{
			for (int j = 1;j < number - 1;j++)
			{
				if (matrix[i][j] == 1)
				{
					int flag = 0,totalt = 0;
					for (int z = 0; z < 4; z++)
					{
						int x = j + dx[z];
						int y = i + dy[z];
						if (matrix[y][x] == 1)
						{
							flag += 1;
							totalt += t[z];
						}
					}
					//printf("%d %d\n", flag,totalt);
					switch (flag)
					{
					case 1:
						deadends++;
						break;
					case 2:
						if (totalt != 20&& totalt != 2)turns++;
						break;
					case 3:
						Tjunctions++;
						break;
					case 4:
						intersection++;
						break;
					default:
						//printf("%3d %3d There is something wrong %3d\n",i,j,flag);
						break;
					}
					//printf("八八八%d\n%d\n%d\n%d\n", intersection, Tjunctions, turns, deadends);
				}
			}
		}
		printf("%d\n%d\n%d\n%d\n", intersection, Tjunctions, turns, deadends);
	}

	return 0;
}