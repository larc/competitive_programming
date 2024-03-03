#include <cstdio>
#include <cstring>

#define N 1000
#define M 2000

struct edge_t
{
	int u, v, t;
};

edge_t edges[M];
int dist[N];

bool relax_edges(const int m)
{
	int d;
	bool relax = false;
	for(int e = 0; e < m; ++e)
	{
		edge_t & edge = edges[e];

		d = dist[edge.u] + edge.t;
		if(d < dist[edge.v])
		{
			dist[edge.v] = d;
			relax = true;
		}
	}

	return relax;
}

int main()
{
	int c, n, m;

	scanf("%d", &c);
	while(c--)
	{
		scanf("%d %d", &n, &m);
		for(int e = 0; e < m; ++e)
			scanf("%d %d %d", &edges[e].u, &edges[e].v, &edges[e].t);

		// Bellman Ford's algorithm
		memset(dist, 0, sizeof(dist));

		while(--n)
			relax_edges(m);

		if(relax_edges(m)) printf("possible\n");
		else printf("not possible\n");
	}
	return 0;
}

