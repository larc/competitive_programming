#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define N 10001
#define L(i) ((i << 1) + 1)
#define R(i) ((i << 1) + 2)
#define P(i) ((i - 1) >> 1)

struct edge_t { int i, v, w; };

std::vector<edge_t> G[N];
int edges[N], cost[N];

int heavy[N], level[N], parent[N];

int dfs(const int & u)
{
	heavy[u] = 0;

	int m_size, size, s;

	m_size = size = 0;
	for(const edge_t & e: G[u])
	{
		if(e.v == parent[u]) continue;

		edges[e.i] = e.v;
		cost[e.v] = e.w;
		parent[e.v] = u;
		level[e.v] = level[u] + 1;

		size += s = dfs(e.v);
		if(m_size < s)
		{
			m_size = s;
			heavy[u] = e.v;
		}
	}

	return size + 1;
}

int head[N], pos[N], ipos[N], current;

void hld(const int & u, const int & h)
{
	head[u] = h;
	ipos[current] = u;
	pos[u] = current++;

	if(heavy[u]) hld(heavy[u], h);

	for(const edge_t & e: G[u])
	{
		if(e.v == parent[u] || e.v == heavy[u])
			continue;

		hld(e.v, e.v);
	}
}

int st[N << 2], idx[N];

int init_st(const int & n, const int & i, const int & j)
{
	if(i == j)
	{
		idx[i] = n;
		return st[n] = ipos[i];
	}

	int m = (i + j) >> 1;

	int l = init_st(L(n), i, m);
	int r = init_st(R(n), m + 1, j);

	return st[n] = cost[l] > cost[r] ? l : r;
}

void update(int i, const int & value)
{
	cost[i] = value;
	i = idx[pos[i]];

	do
	{
		i = P(i);
		const int & l = st[L(i)];
		const int & r = st[R(i)];
		st[i] = cost[l] > cost[r] ? l : r;
	}
	while(i);
}

int rmq(const int & n, const int & i, const int & j, const int & a, const int & b)
{
	if(a <= i && j <= b) return cost[st[n]];
	if(j < a || b < i) return 0;

	int m = (i + j) >> 1;
	int cl = rmq(L(n), i, m, a, b);
	int cr = rmq(R(n), m + 1, j, a, b);

	return std::max(cl, cr);
}

int query(int a, int b, const int & n)
{
	int max = 0;
	while(head[a] != head[b])
	{
		if(level[head[a]] > level[head[b]])
			std::swap(a, b);

		max = std::max(max, rmq(0, 0, n - 1, pos[head[b]], pos[b]));
		b = parent[head[b]];
	}

	if(a == b) return max;

	if(level[a] > level[b])
		std::swap(a, b);

	return std::max(max, rmq(0, 0, n - 1, pos[a] + 1, pos[b]));
}

int main()
{
	char str[8];
	int n_cases, n, u, v, w;
	level[1] = parent[1] = cost[1] = 0;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		for(int i = 1; i < n; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back({i, v, w});
			G[v].push_back({i, u, w});
		}

		current = 0;
		dfs(1); hld(1, 1);
		init_st(0, 0, n - 1);

		while(scanf("%s", str) && str[0] != 'D')
		{
			scanf("%d %d", &u, &v);
			if(str[0] == 'C') update(edges[u], v);
			else printf("%d\n", query(u, v, n));
		}

		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}

	return 0;
}

