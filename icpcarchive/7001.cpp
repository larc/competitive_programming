// 7001 - Bus Problem

#include <cstdio>
#include <algorithm>

#define N 1000
#define M 499500

struct route_t
{
	int u, v, w;
};

bool operator < (const route_t & ra, const route_t & rb)
{
	return ra.w < rb.w;
}

struct union_find
{
	int comp[M];

	void init(const int n)
	{
		for(int i = 0; i < n; ++i)
			comp[i] = i;
	}

	int find(int x)
	{
		if(comp[x] == x) return x;
		return comp[x] = find(comp[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y) return 0;

		comp[y] = x;
		return 1;
	}
};

route_t G[M];
union_find uf;

int kruskal(int n, const int m)
{
	std::sort(G, G + m);
	uf.init(n);

	int cost = 0;
	for(int i = 0; i < m && n; ++i)
		if(uf.join(G[i].u, G[i].v))
		{
			cost += G[i].w;
			n--;
		}

	return cost;
}

int main()
{
	int n, m, n_cases, km;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d", &n, &m);

		km = 0;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &G[i].u, &G[i].v, &G[i].w);
			km += G[i].w;
		}

		printf("%d\n", km - kruskal(n, m));
	}

	return 0;
}

