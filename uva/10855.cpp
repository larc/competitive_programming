// 10855 - Rotated square

#include <cstdio>
#include <cstring>

#define N 1001

int main()
{
	char A[N][N], B[N][N];
	int n, m, count[4];
	bool flag[4];

	while(scanf("%d %d", &n, &m), n && m)
	{
		for(int i = 0; i < n; i++)
			scanf("%s", A[i]);
		for(int i = 0; i < m; i++)
			scanf("%s", B[i]);

		memset(count, 0, sizeof(count));
		for(int i = 0; i <= n - m; i++)
		for(int j = 0; j <= n - m; j++)
		{
			memset(flag, 1, sizeof(flag));
			for(int a = 0; a < m; a++)
			for(int b = 0; b < m; b++)
			{
				if(A[i + a][j + b] != B[a][b]) flag[0] = 0;
				if(A[i + b][j + m - a - 1] != B[a][b]) flag[1] = 0;
				if(A[i + m - a - 1][j + m - b - 1] != B[a][b]) flag[2] = 0;
				if(A[i + m - b - 1][j + a] != B[a][b]) flag[3] = 0;
			}

			for(int k = 0; k < 4; k++)
				if(flag[k]) count[k]++;
		}

		printf("%d %d %d %d\n", count[0], count[1], count[2], count[3]);
	}

	return 0;
}

