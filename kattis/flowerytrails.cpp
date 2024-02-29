#include <cstdio>
#include <vector>
#include <queue>

#define N 10000
#define INF 100000000

int dist[N];
bool visited[N];
std::vector<std::pair<int, int> > G[N];
std::vector<std::pair<int, int> > P[N];

void dijkstra(int u)
{
	std::priority_queue<std::pair<int, int> > q;
	q.push({dist[u] = 0, u});

	int d;
	while(!q.empty())
	{
		d = -q.top().first;
		u = q.top().second;
		q.pop();

		if(d > dist[u]) continue;

		for(auto & p: G[u])
		{
			const int v = p.first;
			const int w = p.second;

			d = w + dist[u];
			if(d > dist[v]) continue;
			if(d == dist[v])
			{
				P[v].push_back({u, w});
				continue;
			}

			dist[v] = d;
			q.push({-d, v});

			P[v].clear();
			P[v].push_back({u, w});
		}
	}
}

int sum_dfs(const int u)
{
	int sum = 0;
	visited[u] = true;

	for(auto & p: P[u])
	{
		sum += p.second;
		if(!visited[p.first])
			sum += sum_dfs(p.first);
	}

	return sum;
}

int main()
{
	int n, m, u, v, w;

	while(scanf("%u %u", &n, &m) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{
			dist[i] = INF;
			visited[i] = false;
			G[i].clear();
		}

		do
		{
			scanf("%d %d %d", &u, &v, &w);
			if(u == v) continue;

			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
		while(--m);

		dijkstra(0);
		printf("%d\n", 2 * sum_dfs(n - 1));
	}

	return 0;
}

