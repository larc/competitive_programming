// 8196 - Imperial Roads
// ACM ICPC 2017 - South America

#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

#define N 100001
#define M 17 // lg(N)

using namespace std;

struct edge_t
{
	int u, v, w;
};

bool operator < (const edge_t & a, const edge_t & b)
{
	return a.w < b.w;
}

edge_t E[N << 1];					// edges array
map<int, int> G[N];					// graph adj
vector<pair<int, int> > T[N];		// mst

struct union_find
{
	int set[N];

	void init(const int & n)
	{
		for(int i = 1; i <= n; ++i)
			set[i] = i;
	}

	int find(const int & x)
	{
		if(set[x] == x) return x;
		return set[x] = find(set[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y) return 0;

		set[y] = x;
		return 1;
	}
} uf;

int kruskal(int n, const int & m)
{
	uf.init(n--);
	sort(E, E + m);

	int cost = 0;
	for(int i = 0; i < m && n; ++i)
	{
		const edge_t & e = E[i];

		if(uf.join(e.u, e.v))
		{
			T[e.u].push_back({e.v, e.w});
			T[e.v].push_back({e.u, e.w});
			cost += e.w;
			n--;
		}
	}

	return cost;
}

int level[N], parent[N], road[N], heavy[N];
int head[N], pos[N], ipos[N], current_pos;
int st[M][N];

int dfs(const int & u)
{
	heavy[u] = 0;

	int max_size = 0, size = 0, v_size;
	for(auto & p: T[u])
	{
		const int & v = p.first;
		const int & w = p.second;

		if(v != parent[u])
		{
			level[v] = level[u] + 1;
			parent[v] = u;
			road[v] = w;

			size += v_size = dfs(v);
			if(v_size > max_size)
			{
				max_size = v_size;
				heavy[u] = v;
			}
		}
	}

	return size + 1;
}

void hld(const int & u, const int & h)
{
	head[u] = h;
	ipos[current_pos] = u;
	pos[u] = current_pos++;

	if(heavy[u]) hld(heavy[u], h);

	for(auto & p: T[u])
	{
		const int & v = p.first;
		const int & w = p.second;

		if(v != parent[u] && v != heavy[u])
			hld(v, v);
	}
}

void init_st(const int & n)
{
	for(int i = 0; i < n; ++i)
		st[0][i] = i;

	int k, u, v;
	for(int i = 1; (1 << i) <= n; ++i)
	{
		k = 1 << (i - 1);
		for(int j = 0; j + (1 << i) - 1 < n; ++j)
		{
			u = st[i - 1][j];
			v = st[i - 1][j + k];
			st[i][j] = road[ipos[u]] > road[ipos[v]] ? u : v;
		}
	}
}

int rmq(int a, int b)
{
	if(b < a) return rmq(b, a);

	int k = log2(b - a + 1);

	a = st[k][a];
	b = st[k][b - (1 << k) + 1];
	return max(road[ipos[a]], road[ipos[b]]);
}

int query(int a, int b)
{
	int qmax, rmax = 0;
	while(head[a] != head[b])
	{
		if(level[head[b]] < level[head[a]])
			swap(a, b);

		qmax = rmq(pos[head[b]], pos[b]);
		rmax = max(rmax, qmax);

		b = parent[head[b]];
	}

	if(a == b) return rmax;

	if(level[b] < level[a])
		swap(a, b);

	qmax = rmq(pos[a] + 1, pos[b]);
	return max(rmax, qmax);
}

int main()
{
	int n, m, q, u, v, w;
	int cost;

	level[1] = parent[1] = road[1] = 0;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			E[i] = {u, v, w};
			G[u][v] = w;
		}

		cost = kruskal(n, m);

		current_pos = 0;
		dfs(1); hld(1, 1);
		init_st(n + 1);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &u, &v);
			printf("%d\n", cost + G[u][v] - query(u, v));
		}

		for(int i = 1; i <= n; ++i)
		{
			T[i].clear();
			G[i].clear();
		}
	}

	return 0;
}

