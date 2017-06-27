//可以用上下做右的座標當位移用for loop跑
//可以將輸入的陣列 上下做右多設各一行為零 
#include <stdio.h>
#include<stdlib.h>

int main() {
	int n, m;
	int **g;
	while (scanf("%d %d", &n, &m) == 2) {
		g = (int **)malloc(n * sizeof(int*));
		for (int i = 0; i < n; i++)
		{
			g[i] = (int *)malloc(m * sizeof(int));
			for (int j = 0; j < m; j++)scanf("%d", &g[i][j]);
		}
		const int dx[] = { 0, 0, 1, -1 };
		const int dy[] = { 1, -1, 0, 0 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int ok = 1;
				for (int k = 0; k < 4; k++) {
					int tx = i + dx[k], ty = j + dy[k];
					if (tx < 0 || ty < 0 || tx >= n || ty >= m)
						continue;
					ok &= g[i][j] > g[tx][ty];
				}
				if (ok)
					printf("%d\n", g[i][j]);
			}
		}
		for (int i = 0; i < n; i++)free(g[i]);
		free(g);
	}
	return 0;
}