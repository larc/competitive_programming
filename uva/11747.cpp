// 11747 - Heavy Cycle Edges

#include <cstdio>
#include <cmath>
#include <queue>

#define N 1000
#define M 25000

struct union_find
{
	int comp[N];
	
	void init(const int & n)
	{
		for(int i = 0; i < n; i++)
			comp[i] = i;
	}

	int find(const int & x)
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

	int n_comp(const int & n)
	{
		int count = 0;
		for(int i = 0; i < n; i++)
			if(comp[i] == i) count++;

		return count;
	}
};

struct edge
{
	int u, v, w;
};

bool operator < (const edge & d, const edge & e)
{
	return d.w > e.w;
}

int main()
{
	int hc_edges[M], n, m, nhce;

	union_find uf;
	edge G[M];
	edge e;
	
	while(scanf("%d %d", &n, &m), n)
	{
		for(int i = 0; i < m; i++)
			scanf("%d %d %d", &G[i].u, &G[i].v, &G[i].w);
		
		nhce = 0;
		if(m)
		{
			std::priority_queue<edge> q(G, G + m);

			uf.init(n);
			while(!q.empty() && n)
			{
				e = q.top(); q.pop();
				if(!uf.join(e.u, e.v))
					hc_edges[nhce++] = e.w;
			}
		}
		
		if(!nhce) printf("forest\n");
		else
		{
			printf("%d", hc_edges[0]);
			for(int i = 1; i < nhce; i++)
				printf(" %d", hc_edges[i]);
			putchar('\n');
		}
	}

	return 0;
}

