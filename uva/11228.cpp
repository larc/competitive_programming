// 11228 - Transportation system

#include <cstdio>
#include <cmath>
#include <queue>

#define N 1000
#define M 500000

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
	int u, v;
	int w;
};

bool operator < (const edge & d, const edge & e)
{
	return d.w > e.w;
}

struct point
{
	int x, y;
};

double dist(const point & p, const point & q)
{
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

int main()
{
	int n_cases, n, m, n_states, r;
	double road, railroad;

	point P[N];
	union_find uf;
	edge G[M];
	edge e;

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; c++)
	{
		scanf("%d %d", &n, &r);
		for(int i = 0; i < n; i++)
			scanf("%d %d", &P[i].x, &P[i].y);
		
		m = 0;
		for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			G[m].w = dist(P[i], P[j]);
			G[m].u = i;
			G[m].v = j;
			m++;
		}

		std::priority_queue<edge> q(G, G + m);
		uf.init(n); n--;
		
		r *= r;
		n_states = 1;
		road = railroad = 0;
		while(!q.empty() && n)
		{
			e = q.top(); q.pop();
			if(uf.join(e.u, e.v))
			{
				n--;
				if(e.w <= r) road += sqrt(e.w);
				else
				{
					railroad += sqrt(e.w);
					n_states++;
				}
			}
		}
		
		printf("Case #%d: %d %d %d\n", c, n_states, (int) (road + 0.5), (int) (railroad + 0.5));
	}

	return 0;
}

