#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

#define N 1024

using namespace std;

int G[N][N]; // adj list
int size[N];
int dfs_low[N]; 
int dfs_num[N];
int dfs_parent[N];
int dfs_counter;

struct link_t
{
	int u, v;
};

bool operator<(const link_t & a, const link_t & b)
{
	if(a.u == b.u) return a.v < b.v;
	return a.u < b.u;
}

set<link_t> links; // critical links
void dfs_bridge(const int & u)
{
	dfs_low[u] = dfs_num[u] = dfs_counter++;
	for(int v, i = 0; i < size[u]; i++)
	{
		v = G[u][i];
		if(dfs_num[v] == -1)
		{
			dfs_parent[v] = u;
			dfs_bridge(v);

			if(dfs_low[v] > dfs_num[u]) // bridge (>= articulation)
				links.insert({min(u,v), max(u,v)});
		
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main()
{
	int n, s, c, nc;
	while(scanf("%d", &n) != EOF)
	{
		memset(size, 0, sizeof(size));

		for(int i = 0; i < n; i++)	
		{
			scanf("%d (%d)", &s, &nc);
			while(nc--)
			{
				scanf("%d", &c);
				G[s][size[s]++] = c;
			}
		}

		links.clear();
		dfs_counter = 0;
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(dfs_low, 0, sizeof(dfs_low));
		memset(dfs_parent, 0, sizeof(dfs_parent));

		for(int i = 0; i < n; i++)
			if(dfs_num[i] == -1)
				dfs_bridge(i);

		printf("%lu critical links\n", links.size());
		for(const link_t & l: links)
			printf("%d - %d\n", l.u, l.v);
		printf("\n");

	}

	return 0;
}

