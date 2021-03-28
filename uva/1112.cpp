// 1112 - Mice and Maze

#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

#define N 101

int G[N][N];
unsigned dist[N];
bool visited[N];

void dijkstra(int u, const int & n)
{
	memset(dist, -1, sizeof(dist));
	memset(visited, 0, sizeof(visited));

	std::priority_queue<std::pair<int, int> > q;
	q.push({0, u});
	dist[u] = 0;

	int m = n;
	while(!q.empty() && m)
	{
		u = q.top().second;
		q.pop();

		if(!visited[u])
		{
			m--;
			visited[u] = 1;

			for(int v = 1; v <= n; ++v)
				if(G[u][v] >= 0 && !visited[v])
					if(dist[v] > dist[u] + G[u][v])
					{
						dist[v] = dist[u] + G[u][v];
						q.push({-dist[v], v});
					}
		}
	}
}

int main()
{
	unsigned n_cases, n, e, t, m, u, v, w;

	scanf("%u", &n_cases);
	while(n_cases--)
	{
		memset(G, -1, sizeof(G));

		scanf("%u %u %u %u", &n, &e, &t, &m);
		while(m--)
		{
			scanf("%u %u %d", &u, &v, &w);
			G[v][u] = w;
		}

		dijkstra(e, n);

		m = 0;
		for(u = 1; u <= n; ++u)
			if(dist[u] <= t) m++;

		printf("%u\n", m);
		if(n_cases) putchar('\n');
	}

	return 0;
}

