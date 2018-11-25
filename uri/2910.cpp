// 2910 - Highway Decommission

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define N 10001

typedef unsigned long long int_t;

struct conn_t
{
	int_t u, l, c;

	operator const int_t & () const
	{
		return u;
	}
};

bool operator < (const conn_t & a, const conn_t & b)
{
	if(a.l == b.l) return a.c > b.c;
	return a.l > b.l;
}

std::vector<conn_t> G[N];
int_t dist[N];
int_t cost[N];

void dijkstra(int_t u)
{
	bool visited[N] = {};
	memset(dist, -1, sizeof(dist));
	memset(cost, 0, sizeof(cost));
	
	dist[u] = 0;

	std::priority_queue<conn_t > q;
	q.push({u, 0, 0});
	
	while(!q.empty())
	{
		u = q.top(); q.pop();
		visited[u] = 1;

		for(conn_t & v: G[u]) if(!visited[v])
			if(dist[v] > dist[u] + v.l)
			{
				dist[v] = dist[u] + v.l;
				cost[v] = v.c;
				q.push({v, dist[v], v.c});
			}
			else if(dist[v] == dist[u] + v.l && cost[v] > v.c)
			{
				cost[v] = v.c;
				q.push({v, dist[v], v.c});
			}
	}
}

int main()
{
	int_t n, m, a, b, l, c;
	
	scanf("%llu %llu", &n, &m);
	while(m--)
	{
		scanf("%llu %llu %llu %llu", &a, &b, &l, &c);
		
		G[a].push_back({b, l, c});
		G[b].push_back({a, l, c});
	}
	
	dijkstra(1);

	c = 0;
	for(a = 1; a <= n; a++)
		c += cost[a];
	
	printf("%llu\n", c);
	return 0;
}

