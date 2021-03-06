#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define N 98
#define INF 1000000000

int W[N][N];	// cost edges
int G[N][N];	// adj list
int size[N];	
int path[N];

int augment(const int & v, int cost_path)
{
	if(path[v] >= 0 && path[v] != v)
	{
		cost_path = augment(path[v], std::min(cost_path, W[path[v]][v]));
		W[path[v]][v] -= cost_path;
		W[v][path[v]] += cost_path;
	}
	
	return cost_path;
}

int bfs(const int & s, const int & t)
{
	memset(path, -1, sizeof(path));
	path[s] = s;

	std::queue<int> q;
	q.push(s);

	int u, v;
	while(!q.empty())
	{
		u = q.front();
		q.pop();

		if(u == t) break;

		for(int i = 0; i < size[u]; ++i)
		{
			v = G[u][i];
			if(W[u][v] > 0 && path[v] == -1)
			{
				path[v] = u;
				q.push(v);
			}
		}
	}

	return augment(t, INF);
}

int index_source(const int & u, const int & m)
{
	if(u == 1) return 0;
	if(u == m) return 1;
	return (u - 1) << 1;
}

int index_target(const int & u, const int & m)
{
	if(u == 1) return 0;
	if(u == m) return 1;
	return ((u - 1) << 1) + 1;
}

void add_edge(const int & x, const int & y, const int & c, const int & m)
{
	int u = index_target(x, m);
	int v = index_source(y, m);

	G[u][size[u]++] = v;
	G[v][size[v]++] = u;

	if(x != y) W[u][v] = c;
	else W[v][u] = c;
}

int main()
{
	int m, w, u, v, c;
	while(scanf("%d %d", &m, &w), m || w)
	{
		memset(size, 0, sizeof(size));
		memset(W, 0, sizeof(W));

		for(int i = 2; i < m; ++i)
		{
			scanf("%d %d", &u, &c);
			add_edge(u, u, c, m);
		}

		while(w--)
		{
			scanf("%d %d %d", &u, &v, &c);

			add_edge(u, v, c, m);
			add_edge(v, u, c, m);
		}
		
		c = 0;
		while((w = bfs(0, 1)) < INF)
			c += w;

		printf("%d\n", c);
	}

	return 0;
}

