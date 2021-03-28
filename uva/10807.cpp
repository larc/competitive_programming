// 10807 - Prim

#include <cstdio>
#include <algorithm>

#define N 11
#define M 25

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
};

struct edge
{
	int u, v, w;
};

bool operator < (const edge & a, const edge & b)
{
	return a.w < b.w;
}

int n, m, max_cost;
edge G[M];	// graph list of edges

void dfs(const int & i, const int & na, const int & nb,
						const int & ca, const int & cb,
						const union_find & ufa, const union_find & ufb)
{
	if(ca + cb >= max_cost) return;

	if(na == n - 1 && nb == n - 1)
	{
		max_cost = ca + cb;
		return;
	}

	if(((n << 1) - 2 - na - nb) * G[i].w >= max_cost - ca - cb) return;
	if((n << 1) - 2 - na - nb > m - i) return;

	union_find uf;
	bool select = 0;

	uf = ufa;
	if(uf.join(G[i].u, G[i].v))
	{
		select = 1;
		dfs(i + 1, na + 1, nb, ca + G[i].w, cb, uf, ufb);
	}

	uf = ufb;
	if(uf.join(G[i].u, G[i].v))
	{
		select = 1;
		dfs(i + 1, na, nb + 1, ca, cb + G[i].w, ufa, uf);
	}

	if(!select) dfs(i + 1, na, nb, ca, cb, ufa, ufb);
}

int main()
{
	union_find ufa, ufb;

	int inf;
	while(scanf("%d", &n) && n)
	{
		scanf("%d", &m);

		max_cost = 1;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &G[i].u, &G[i].v, &G[i].w);
			max_cost += G[i].w;
		}

		std::sort(G, G + m);

		inf = max_cost;
		ufa.init(n);
		ufb.init(n);
		dfs(0, 0, 0, 0, 0, ufa, ufb);

		if(max_cost < inf) printf("%d\n", max_cost);
		else printf("No way!\n");
	}

	return 0;
}

