#include <cstdio>
#include <cstring>
#include <map>

#define N 1001

int G[N][N]; // 1 - index
int size[N];
bool visited[N];

int match[N];

bool augmenting_path(const int u) // dfs: mcbm
{
		if(visited[u]) return 0;

		visited[u] = 1;

		for(int i = 0; i < size[u]; ++i)
		{
			const int v = G[u][i];
			if(match[v] == -1 || augmenting_path(match[v]))
			{
				match[v] = u;
				return 1;
			}
		}

		return 0;
}

int main()
{
	int n, m, u, v;

	scanf("%d %d", &n, &m);

	memset(size, 0, sizeof(size));

	while(m--)
	{
		scanf("%d %d", &u, &v);

		G[u][size[u]++] = v;
		G[v][size[v]++] = u;
	}

	m = 0;
	memset(match, -1, sizeof(match));

	for(int u = 1; u <= n; ++u)
	{
		memset(visited, 0, sizeof(visited));
		m += augmenting_path(u);
	}

	if(m == n)
	{
		for(int u = 1; u <= n; ++u)
			printf("%d\n", match[u]);
	}
	else printf("Impossible\n");

	return 0;
}

