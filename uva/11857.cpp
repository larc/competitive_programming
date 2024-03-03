// 11857 - Driving Range

#include <cstdio>
#include <algorithm>

#define N 1000000

struct union_find
{
	int P[N];

	void init(const int n)
	{
		for(int i = 0; i < n; ++i)
			P[i] = i;
	}

	int find(const int x)
	{
		return P[x] = x == P[x] ? x : find(P[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y)
			return false;

		P[y] = x;
		return true;
	}
};

struct edge_t
{
	int u, v, w;

	bool operator < (const edge_t & e)
	{
		return w < e.w;
	}
};


union_find uf;
edge_t G[N];

int kruskal(const int n, const int m)
{
	uf.init(n);
	std::sort(G, G + m);

	int count = 0;
	for(int i = 0; i < m; ++i)
	{
		edge_t & e = G[i];
		if(uf.join(e.u, e.v))
		{
			if(++count == n - 1)
				return e.w;
		}
	}

	return -1;
}

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m), n)
	{
		for(int i = 0; i < m; ++i)
		{
			edge_t & e = G[i];
			scanf("%d %d %d", &e.u, &e.v, &e.w);
		}

		m = kruskal(n, m);
		m == -1 ? printf("IMPOSSIBLE\n") : printf("%d\n", m);
	}

	return 0;
}

