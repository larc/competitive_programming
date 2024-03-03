// 11906 - Knight in a War Grid

#include <cstdio>
#include <cstring>

#define N 100

int grid[N][N], r, c, m, n;

void dfs(const int x, const int y)
{
	if(x < 0 || y < 0) return;
	if(x >= r || y >= c) return;
	if(grid[x][y] == -1) return;
	if(grid[x][y]++) return;

	dfs(x + n, y + m);
	dfs(x - n, y + m);
	dfs(x + n, y - m);
	dfs(x - n, y - m);

	dfs(x + m, y + n);
	dfs(x - m, y + n);
	dfs(x + m, y - n);
	dfs(x - m, y - n);
}

int main()
{
	int n_cases, w, x, y;

	scanf("%d", &n_cases);
	for(int ic = 1; ic <= n_cases; ++ic)
	{
		scanf("%d %d %d %d", &r, &c, &m, &n);
		memset(grid, 0, sizeof(grid));

		scanf("%d", &w);
		while(w--)
		{
			scanf("%d %d", &x, &y);
			grid[x][y] = -1;
		}

		dfs(0, 0); grid[0][0]--;

		x = y = 0;
		for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			if(grid[i][j] > 0)
			{
				if(!m || !n || m == n) grid[i][j] >>= 1;
				x += !(grid[i][j] & 1);
				y += grid[i][j] & 1;
			}

		if(!x && !y) x = 1;
		printf("Case %d: %d %d\n", ic, x, y);
	}

	return 0;
}

