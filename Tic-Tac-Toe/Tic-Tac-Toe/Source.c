#include<stdlib.h>
#include<stdio.h>
#include<process.h>

int main(void)
{
	int result = 0, step;
	scanf("%d", &step);
	int x, y;
	char who = 0;
	int tic[] = { 10,100 };
	int chessboard[3][3] = { {0} };

	while (scanf("%d%d", &x, &y) == 2 &&--step!=0&& result==0)
	{
		if (x < 0 || x>2 || y < 0 || y>2 || chessboard[y][x] != 0)
		{
			//printf("Wrong\n");
			continue;
		}
		chessboard[y][x] = tic[who];
		who ^= 1;
		int answer=0;
		//printf("-----\n");
		//for (int i = 0;i < 3;i++)for (int j = 0;j < 3;j++)printf(j == 2 ? "%3d\n" : "%3d ", chessboard[i][j]);
		//printf("-----\n");
		for (int i = 0; i < 3; i++)//¾î±Æ
		{
			for (int j = 0; j < 3; j++)
			{
				answer += chessboard[i][j];
				if (answer == 30)
				{
					printf("Black wins.\n");
					result = 1;
				}
				if (answer == 300)
				{
					printf("White wins.\n");
					result = 1;
				}
			}
			answer = 0;
		}
			for (int i = 0; i < 3; i++)//ª½±Æ
			{
				for (int j = 0; j < 3; j++)
				{
					answer += chessboard[j][i];
					if (answer == 30)
					{
						printf("Black wins.\n");
						result = 1;
					}
					if (answer == 300)
					{
						printf("White wins.\n");
						result = 1;
					}
				}
				answer = 0;
			}
			if ((chessboard[0][0] + chessboard[1][1] + chessboard[2][2]) == 30)
			{
				printf("Black wins.\n");
				result = 1;
			}
			if ((chessboard[0][0] + chessboard[1][1] + chessboard[2][2]) == 300)
			{
				printf("White wins.\n");
				result = 1;
			}
			if ((chessboard[0][2] + chessboard[1][1] + chessboard[2][0]) == 30)
			{
				printf("Black wins.\n");
				result = 1;
			}
			if ((chessboard[0][2] + chessboard[1][1] + chessboard[2][0]) == 300)
			{
				printf("White wins.\n");
				result = 1;
			}
			//printf("step: %d\n", step);
			
	}
	if (result == 0||step==0)printf("There is a draw.\n");

	system("pause");

	return 0;
}