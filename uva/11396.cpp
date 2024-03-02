// 11396 - Claw Decomposition

#include <cstdio>
#include <cstring>

#define N 301

int G[N][N];
int size[N];
int visited[N];

bool dfs(const int u, const bool b)
{
	visited[u] = b;
	for(int i = 0; i < size[u]; ++i)
	{
		const int v = G[u][i];
		if(visited[v] != -1 && visited[v] == b)
			return 0;
		if(visited[v] == -1 && !dfs(v, !b))
			return 0;
	}

	return 1;
}

bool claw(const int n)
{
	memset(visited, -1, sizeof(visited));

	for(int u = 1; u <= n; ++u)
		if(visited[u] == -1 && !dfs(u, 0))
			return 0;

	return 1;
}

int main()
{
	int n, u, v;

	while(scanf("%d", &n) && n)
	{
		memset(size, 0, sizeof(size));

		while(scanf("%d %d", &u, &v), u && v)
		{
			G[u][size[u]++] = v;
			G[v][size[v]++] = u;
		}

		if(claw(n)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

