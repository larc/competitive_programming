// 2910 - Highway Decommission

#include <cstdio>
#include <cstring>
#include <queue>

#define N 10001
#define M 200002

typedef unsigned long long llu_t;

struct conn_t
{
	int u;
	llu_t l, c;

	operator const int & () const
	{
		return u;
	}
};

bool operator < (const conn_t & a, const conn_t & b)
{
	if(a.l == b.l) return a.c > b.c;
	return a.l > b.l;
}

// compact graph structure for: #edges << #nodes^2

int begin[N], end[N], next[M];
conn_t G[M]; int current;

void add(const int & u, const conn_t & conn)
{
	if(begin[u] < 0) begin[u] = end[u] = current;
	else end[u] = next[end[u]] = current;
	
	G[current++] = conn;
}

llu_t dist[N];
llu_t cost[N];
bool visited[N];

void dijkstra(int u)
{
	memset(dist, -1, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	
	std::priority_queue<conn_t> q;

	q.push({u, dist[u] = 0, cost[u] = 0});
	
	while(!q.empty())
	{
		u = q.top(); q.pop();

		if(visited[u]) continue;
	
		visited[u] = 1;

		for(int i = begin[u]; i != -1; i = next[i])
		{
			const conn_t & v = G[i];
			
			if(visited[v]) continue;

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
}

int main()
{
	int n, m, a, b;
	llu_t l, c;
	
	memset(begin, -1, sizeof(begin));
	memset(next, -1, sizeof(next));
	
	current = 0;
	
	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d %d %llu %llu", &a, &b, &l, &c);
		
		add(a, {b, l, c});
		add(b, {a, l, c});
	}
	
	dijkstra(1);

	c = 0;
	for(a = 1; a <= n; ++a)
		c += cost[a];
	
	printf("%llu\n", c);
	return 0;
}

