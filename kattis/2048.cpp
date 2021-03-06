#include <cstdio>
#include <cstring>

#define N 4

int grid[N][N];
int rgrid[N][N];

void rotate()
{
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j)
		rgrid[N - j - 1][i] = grid[i][j];
	
	memcpy(grid, rgrid, sizeof(rgrid));
}

int main()
{
	int n, k;

	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j)
		scanf("%d", &grid[i][j]);
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i)
		rotate();
	
	memset(rgrid, 0, sizeof(rgrid));
	for(int i = 0; i < N; ++i)
	{
		k = 0;
		for(int j = 0; j < N; ++j)
		{
			if(grid[i][j])
				rgrid[i][k++] = grid[i][j];
			
			grid[i][j] = 0;
		}

		k = 0;
		for(int j = 0; j < N; ++j)
			if(j < N - 1 && rgrid[i][j] == rgrid[i][j + 1])
				grid[i][k++] = rgrid[i][j++] << 1;
			else
				grid[i][k++] = rgrid[i][j];
	}

	n = (4 - n) % 4;
	for(int i = 0; i < n; ++i)
		rotate();
	
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j)
		printf("%d%c", grid[i][j], j == N - 1 ? '\n' : ' ');
	
	return 0;
}

