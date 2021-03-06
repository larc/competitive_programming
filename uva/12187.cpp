#include <cstdio>

int main()
{
	int land[100][100][2];
	int a, i, j;
	int N, R, C, K;

	while(scanf("%d %d %d %d", &N, &R, &C, &K) && N)
	{
		a = 0;
		for(i = 0; i < R; ++i)
			for(j = 0; j < C; ++j)
				scanf("%d", &land[i][j][a]);

		while(K--)
		{
			for(i = 0; i < R; ++i)
				for(j = 0; j < C; ++j)
					land[i][j][!a] = land[i][j][a];

			for(i = 0; i < R; ++i)
				for(j = 0; j < C; ++j)
				{
					if(j < C - 1 && (land[i][j][a] + 1 ) % N == land[i][j + 1][a])
						land[i][j + 1][!a] = land[i][j][a];
					if(j > 0 && (land[i][j][a] + 1 ) % N == land[i][j - 1][a])
						land[i][j - 1][!a] = land[i][j][a];
					if(i < R - 1 && (land[i][j][a] + 1 ) % N == land[i + 1][j][a])
						land[i + 1][j][!a] = land[i][j][a];
					if(i > 0 && (land[i][j][a] + 1 ) % N == land[i - 1][j][a])
						land[i - 1][j][!a] = land[i][j][a];
				}
			a = !a;
		}


		for(i = 0; i < R; ++i)
		{
			printf("%d", land[i][0][a]);
			for(j = 1; j < C; ++j)
				printf(" %d", land[i][j][a]);
			printf("\n");
		}
	}

	return 0;
}
