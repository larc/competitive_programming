#include <cstdio>
#include <cstring>
#include <vector>

#define N 300001

std::vector<int> G[N];
int parent[N], red[N], blue[N], color[N];

void dfs(const int & u)
{
	red[u] = blue[u] = 0;
	if(color[u] == 1) red[u]++;
	if(color[u] == 2) blue[u]++;

	for(const int & v: G[u])
	{
		if(parent[v] != -1) continue;

		parent[v] = u;
		dfs(v);

		red[u] += red[v];
		blue[u] += blue[v];
	}
}

int main()
{
	int n, u, v, count;

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", color + i);

	for(int i = 1; i < n; ++i)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	memset(parent, -1, sizeof(parent));
	parent[1] = 0;
	dfs(1);

	count = 0;
	for(int i = 2; i <= n; ++i)
		count += (!(red[1] - red[i]) && !blue[i]) || (!(blue[1] - blue[i]) && !red[i]);

	printf("%d\n", count);

	return 0;
}

