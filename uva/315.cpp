#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>

#define N 100

int G[N][N];
int size[N];
int dfs_low[N]; 
int dfs_num[N];
int dfs_parent[N];
int dfs_counter;

void dfs_articulation(const int & u, int & count)
{
	dfs_low[u] = dfs_num[u] = dfs_counter++;
	for(int v, i = 0; i < size[u]; i++)
	{
		v = G[u][i];
		if(dfs_num[v] == -1)
		{
			dfs_parent[v] = u;
			dfs_articulation(v, count);

			if(dfs_low[v] >= dfs_num[u]) // articulation
				count++;

			dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u])
			dfs_low[u] = std::min(dfs_low[u], dfs_num[v]);
	}
}

int main()
{
	char line[512];
	std::stringstream ss;

	int n, u, v, count;
	while(scanf("%d", &n), n)
	{
		memset(size, 0, sizeof(size));

		while(scanf("%d", &u), u)
		{
			fgets(line, sizeof(line), stdin);
			ss << line;
			while(ss >> v)
			{
				G[u][size[u]++] = v;
				G[v][size[v]++] = u;
			}
		}
		
		dfs_counter = 0;
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(dfs_low, 0, sizeof(dfs_low));
		memset(dfs_parent, 0, sizeof(dfs_parent));
		
		count = 0;
		for(u = 0; u < n; u++)
			if(dfs_num[u] == -1)
				dfs_articulation(u, count);
		
		printf("%d\n", count);
	}

	return 0;
}

