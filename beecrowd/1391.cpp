// 1391 - Almost Shortest Path

#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

#define N 500
#define INF (0u - 1)

typedef unsigned int uint_t;

uint_t G[N][N];
uint_t W[N][N];
uint_t size[N];
uint_t dist[N];
uint_t path[N][N];
uint_t spath[N];
bool visited[N];

void dijkstra(uint_t s, const uint_t d)
{
	memset(dist, INF, sizeof(dist));
	memset(path, INF, sizeof(dist));
	memset(visited, 0, sizeof(visited));

	dist[s] = 0;
	spath[s] = 0;

	std::priority_queue<std::pair<uint_t, uint_t> > q;
	q.push({0, s});

	uint_t u;
	while(!q.empty())
	{
		u = q.top().second;
		q.pop();

		if(u == d) return;

		if(!visited[u])
		{
			visited[u] = 1;
			for(uint_t i = 0; i < size[u]; ++i)
			{
				const uint_t v = G[u][i];
				if(!visited[v] && W[u][v] > 0)
				{
					if(dist[u] + W[u][v] < dist[v])
					{
						spath[v] = 0;
						path[v][spath[v]++] = u;
						dist[v] = dist[u] + W[u][v];
						q.push({-dist[v], v});
					}
					else if(dist[u] + W[u][v] == dist[v])
						path[v][spath[v]++] = u;
				}
			}
		}
	}
}

void delete_node(const uint_t u)
{
	if(!spath[u]) return;

	for(uint_t i = 0; i < spath[u]; ++i)
	{
		W[path[u][i]][u] = 0;
		delete_node(path[u][i]);
	}
}

int main()
{
	uint_t n, m, s, d, u, v, w;

	while(scanf("%d %d", &n, &m) && n)
	{
		scanf("%d %d", &s, &d);

		memset(size, 0, sizeof(size));
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			G[u][size[u]++] = v;
			W[u][v] = w;
		}

		dijkstra(s, d);
		if(dist[d] != INF)
		{
			delete_node(d);
			dijkstra(s, d);
		}

		printf("%d\n", dist[d]);
	}

	return 0;
}

