// 10600 - ACM Contest and Blackout

#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 101
#define M 4950

struct union_find
{
	int comp[N];

	void init(const int n)
	{
		for(int i = 1; i <= n; ++i)
			comp[i] = i;
	}

	int find(const int x)
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

	int n_comp(const int n)
	{
		int count = 0;
		for(int i = 1; i <= n; ++i)
			if(comp[i] == i) count++;

		return count;
	}
};

struct edge
{
	int u, v, w;
	bool operator < (const edge & e)
	{
		return w < e.w;
	}
};

int main()
{
	int n_cases, n, m, cost, min_cost;
	edge G[M];
	union_find uf;
	bool mst[M];

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; ++i)
			scanf("%d %d %d", &G[i].u, &G[i].v, &G[i].w);

		std::sort(G, G + m);
		memset(mst, 0, sizeof(mst));

		// kruskal
		uf.init(n);
		cost = 0;
		for(int i = 0; i < m; ++i)
			if(uf.join(G[i].u, G[i].v))
			{
				mst[i] = 1;
				cost += G[i].w;
			}

		printf("%d ", cost);

		min_cost = cost * n;
		for(int i = 0; i < m; ++i) if(mst[i])
		{
			uf.init(n);
			cost = 0;
			for(int j = 0; j < m; ++j)
				if(i != j && uf.join(G[j].u, G[j].v))
					cost += G[j].w;

			if(uf.n_comp(n) == 1 && cost < min_cost) min_cost = cost;
		}

		printf("%d\n", min_cost);
	}

	return 0;
}

