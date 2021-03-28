// 10765 - Doves and bombs

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define N 10000

struct bomb_t { int s, p; };

bool operator < (const bomb_t & a, const bomb_t & b)
{
	if(a.p == b.p) return a.s < b.s;
	return a.p > b.p;
}

std::vector<int> G[N];
bomb_t bombs[N]; int nb;

int n_comp[N];
int parent[N], dfs_num[N], dfs_low[N], dfs_count;
void articulations(const int & u, const int & n)
{
	dfs_num[u] = dfs_low[u] = dfs_count++;

	for(int & v: G[u])
	{
		if(dfs_num[v] == -1)	// unvisited
		{
			parent[v] = u;
			n_comp[v] = 1;
			articulations(v, n);

			if(dfs_low[v] >= dfs_num[u])
				n_comp[u]++;	// counting the number of components

			dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
		}
		else if(v != parent[u])
			dfs_low[u] = std::min(dfs_low[u], dfs_num[v]);
	}

	bombs[nb++] = {u, n_comp[u]};
}

int main()
{
	int n, m, x, y;
	while(scanf("%d %d", &n, &m) && n && m)
	{
		while(scanf("%d %d", &x, &y) && x >= 0 && y >= 0)
		{
			G[x].push_back(y);
			G[y].push_back(x);
		}

		memset(dfs_num, -1, sizeof(dfs_num));

		n_comp[0] = 0;
		nb = 0; dfs_count = 0;
		articulations(0, n);
		std::sort(bombs, bombs + nb);

		for(int i = 0; i < m; ++i)
			printf("%d %d\n", bombs[i].s, bombs[i].p);

		putchar('\n');

		for(int i = 0; i < n; ++i)
			G[i].clear();
	}

	return 0;
}

