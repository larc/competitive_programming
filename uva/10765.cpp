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

bool visited[N];
void dfs(const int & u, const int & b)
{
	if(u == b) return;

	visited[u] = 1;
	for(int & v: G[u])
		if(!visited[v]) dfs(v, b);
}

int count_components(const int & n, const int & b)
{
	memset(visited, 0, sizeof(visited));

	int nc = 0;
	for(int i = 0; i < n; i++)
		if(!visited[i] && i != b)
			nc++, dfs(i, b);

	return nc;
}

bool marked[N];
int parent[N], dfs_num[N], dfs_low[N], dfs_count; 
void articulations(const int & u, const int & n)
{
	dfs_num[u] = dfs_low[u] = dfs_count++;
	
	for(int & v: G[u])
	{
		if(dfs_num[v] == -1)	// unvisited
		{
			parent[v] = u;
			articulations(v, n);

			if(dfs_low[v] >= dfs_num[u] && !marked[u])
			{
				bombs[nb++] = {u, count_components(n, u)};
				marked[u] = 1;
			}

			dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
		}
		else if(v != parent[u])
			dfs_low[u] = std::min(dfs_low[u], dfs_num[v]);
	}

	if(!marked[u])
	{
		bombs[nb++] = {u, 1};
		marked[u] = 1;
	}
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
		memset(marked, 0, sizeof(marked));

		nb = 0; dfs_count = 0;
		articulations(0, n);
		std::sort(bombs, bombs + nb);

		for(int i = 0; i < m; i++)
			printf("%d %d\n", bombs[i].s, bombs[i].p);
		
		putchar('\n');

		for(int i = 0; i < n; i++)
			G[i].clear();
	}
	
	return 0;
}

