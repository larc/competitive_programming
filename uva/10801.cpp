#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>

#define E 5		// elevators
#define N 100	// floors

struct floor_t
{
	int e, n;			// elevator, floor
	unsigned int d;		// distance
};

bool operator<(const floor_t & a, const floor_t & b)
{
	return a.d > b.d;
}

unsigned int T[E];
int G[E][N][2];
unsigned int dist[E][N];
bool visited[E][N];

bool stop(const int e, const int n)
{
	return G[e][n][0] >= 0 || G[e][n][1] >= 0;
}

void relax(const int e, const int n, const int fe, const int fn, std::priority_queue<floor_t> & q)
{
	if(fn < 0) return;
	if(!stop(fe, fn)) return;
	if(visited[fe][fn]) return;

	unsigned int d = dist[e][n];
	if(e == fe) d += T[e] * abs(fn - n);
	else d += 60;

	if(d < dist[fe][fn])
	{
		dist[fe][fn] = d;
		q.push({fe, fn, d});
	}
}

unsigned int dijkstra(const int k)
{
	memset(visited, 0, sizeof(visited));
	memset(dist, -1, sizeof(dist));

	std::priority_queue<floor_t> q;

	int n, e;
	for(e = 0; e < E; ++e)
		if(stop(e, 0))
		{
			dist[e][0] = 0;
			q.push({e, 0, 0});
		}

	while(!q.empty())
	{
		e = q.top().e;
		n = q.top().n;
		q.pop();

		if(!visited[e][n])
		{
			visited[e][n] = 1;
			if(n == k) return dist[e][n];

			relax(e, n, e, G[e][n][0], q);
			relax(e, n, e, G[e][n][1], q);

			for(int fe = 0; fe < E; ++fe)
				relax(e, n, fe, n, q);
		}
	}

	return -1;
}

int main()
{
	int n, k, u, v;
	char line[256];
	std::stringstream ss;
	unsigned int d;

	while(scanf("%d %d", &n, &k) != EOF)
	{
		memset(G, -1, sizeof(G));

		for(int i = 0; i < n; ++i)
			scanf("%u", T + i);

		getchar();
		for(int i = 0; i < n; ++i)
		{
			fgets(line, sizeof(line), stdin);
			ss.clear();
			ss << line;

			ss >> u;
			while(ss >> v)
			{
				G[i][u][1] = v;
				G[i][v][0] = u;
				u = v;
			}
		}

		d = dijkstra(k);
		if(d < 0u - 1) printf("%u\n", d);
		else printf("IMPOSSIBLE\n");
	}

	return 0;
}

