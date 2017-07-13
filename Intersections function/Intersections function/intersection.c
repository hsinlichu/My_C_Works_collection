#include<stdio.h>
#include"intersection.h"
#define number 102
void intersection(int map[100][100], int result[4])
{
	for (int i = 0; i < 4;++i)result[i] = 0;
	int matrix[number][number] = { {0} };
	for (int i = 1; i < number - 1; i++)for (int j = 1; j < number - 1; j++)matrix[i][j] = map[i - 1][j - 1];

	const int dx[] = { 0,1,0,-1 };//上右下左
	const int dy[] = { -1,0,1,0 };
	const int  t[] = { 1,10,1,10 };
	for (int i = 1; i < number - 1; i++)
	{
		for (int j = 1;j < number - 1;j++)
		{
			if (matrix[i][j] == 1)
			{
				int flag = 0, totalt = 0;
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
					result[3]++;
					break;
				case 2:
					if (totalt != 20 && totalt != 2)result[2]++;
					break;
				case 3:
					result[1]++;
					break;
				case 4:
					result[0]++;
					break;
				default:
					//printf("%3d %3d There is something wrong %3d\n",i,j,flag);
					break;
				}
				//printf("八八八%d\n%d\n%d\n%d\n", intersection, Tjunctions, turns, deadends);
			}
		}
	}
}
