#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define N 100000


std::vector<int> G[N];

int level[N] = {};
bool visited[N] = {};


int dfs(const int u)
{
	visited[u] = true;

	int fu, fv;

	fu = u;
	for(const int v: G[u])
	{
		if(level[v] >= 0) continue;

		level[v] = level[u] + 1;

		fv = dfs(v);
		if(level[fv] > level[fu])
			fu = fv;
	}

	return fu;
}

int farthest(const int u)
{
	memset(level, -1, sizeof(level));
	level[u] = 0;

	return dfs(u);
}

int diameter(const int u)
{
	return level[farthest(farthest(u))];
}

int main()
{
	std::vector<int> D;
	D.reserve(N);

	int n, m, u, v;

	scanf("%d %d", &n, &m);

	while(m--)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(int i = 0; i < n; ++i)
	{
		if(visited[i]) continue;
		D.push_back(diameter(i));
	}

	std::sort(begin(D), end(D), std::greater<>());

	m = -1;
	for(const int d: D)
	{
		u = (m + 1) >> 1;
		v = (d + 1) >> 1;
		m = std::max({m, d, u + v + 1});
	}

	printf("%d\n", m);

	return 0;
}

