#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define INF 10000000
#define N 100001
#define M 17

std::vector<std::pair<int, int> > G[N];

int level[N], parent[N], road[N], heavy[N];
int head[N], pos[N], ipos[N], current_pos;
int max_st[M][N], min_st[M][N];

int dfs(const int u)
{
	heavy[u] = 0;

	int max_size = 0, size = 0, v_size;
	for(auto & p: G[u])
	{
		const int v = p.first;
		const int w = p.second;

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

void hld(const int u, const int h)
{
	head[u] = h;
	ipos[current_pos] = u;
	pos[u] = current_pos++;

	if(heavy[u]) hld(heavy[u], h);

	for(auto & p: G[u])
	{
		const int v = p.first;
		const int w = p.second;

		if(v != parent[u] && v != heavy[u])
			hld(v, v);
	}
}

void init_st(const int n)
{
	for(int i = 0; i < n; ++i)
	{
		min_st[0][i] = i;
		max_st[0][i] = i;
	}

	int k, u, v;
	for(int i = 1; (1 << i) <= n; ++i)
	{
		k = 1 << (i - 1);
		for(int j = 0; j + (1 << i) - 1 < n; ++j)
		{
			u = min_st[i - 1][j];
			v = min_st[i - 1][j + k];
			min_st[i][j] = road[ipos[u]] < road[ipos[v]] ? u : v;

			u = max_st[i - 1][j];
			v = max_st[i - 1][j + k];
			max_st[i][j] = road[ipos[u]] > road[ipos[v]] ? u : v;
		}
	}
}

int qmax, qmin;
void rmq(const int a, const int b)
{
	if(b < a) rmq(b, a);

	int i, j, k = log2(b - a + 1);

	i = min_st[k][a];
	j = min_st[k][b - (1 << k) + 1];
	qmin = std::min(road[ipos[i]], road[ipos[j]]);

	i = max_st[k][a];
	j = max_st[k][b - (1 << k) + 1];
	qmax = std::max(road[ipos[i]], road[ipos[j]]);
}

int rmax, rmin;
void query(int a, int b)
{
	rmax = 0; rmin = INF;
	while(head[a] != head[b])
	{
		if(level[head[b]] < level[head[a]])
			std::swap(a, b);

		rmq(pos[head[b]], pos[b]);
		rmin = std::min(rmin, qmin);
		rmax = std::max(rmax, qmax);

		b = parent[head[b]];
	}

	if(a == b) return;

	if(level[b] < level[a])
		std::swap(a, b);

	rmq(pos[a] + 1, pos[b]);
	rmin = std::min(rmin, qmin);
	rmax = std::max(rmax, qmax);
}

int main()
{
	int n, q, u, v, w;

	level[1] = parent[1] = road[1] = 0;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i < n; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}

		current_pos = 0;
		dfs(1); hld(1, 1);
		init_st(n + 1);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &u, &v);
			query(u, v);
			printf("%d %d\n", rmin, rmax);
		}

		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}

	return 0;
}

