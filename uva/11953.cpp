// 11953 - Battleships

#include <cstdio>
#include <cstring>

#define N 102

char grid[N][N];
bool visited[N][N];

void dfs(const int & i, const int & j, int & x, int & h)
{
	if(visited[i][j]) return;
	if(!grid[i][j] || grid[i][j] == '.') return;

	visited[i][j] = 1; x++;
	if(grid[i][j] == '@') h++;

	dfs(i - 1, j, x, h);
	dfs(i + 1, j, x, h);
	dfs(i, j - 1, x, h);
	dfs(i, j + 1, x, h);
}

int main()
{
	int n_cases, n, alive, x, h;

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		memset(grid, 0, sizeof(grid));
		memset(visited, 0, sizeof(visited));

		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%s", grid[i] + 1);

		alive = 0;
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(!visited[i][j])
			{
				x = h = 0;
				dfs(i, j, x, h);
				alive += x > h;
			}

		printf("Case %d: %d\n", c, alive);
	}

	return 0;
}

