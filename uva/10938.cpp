// 10938 - Flea circus

#include <cstdio>
#include <cmath>
#include <vector>

#define N 100000
#define M 18

using namespace std;

vector<int> G[N];
int parent[N];
int level[N];

int idx[N], euler[N << 1];	// euler tour
int st[M][N << 1];			// sparse table

void dfs(const int & u, int & m)
{
	idx[u] = m;
	euler[m++] = u;

	for(const int & v: G[u]) if(parent[u] != v)
	{
		level[v] = level[u] + 1;
		parent[v] = u;

		dfs(v, m);
		euler[m++] = u;
	}
}

void init_st(const int & m)
{
	for(int i = 0; i < m; ++i)
		st[0][i] = i;

	int k;
	for(int i = 1; (1 << i) <= m; ++i)
	{
		k = 1 << (i - 1);
		for(int j = 0; j + (1 << i) - 1 < m; ++j)
		{
			const int & u = st[i - 1][j];
			const int & v = st[i - 1][j + k];
			st[i][j] = level[euler[u]] < level[euler[v]] ? u : v;
		}
	}
}

int lca(const int & a, const int & b)
{
	if(b < a) return lca(b, a);

	int k = log2(b - a + 1);

	const int & i = st[k][a];
	const int & j = st[k][b - (1 << k) + 1];

	return level[euler[i]] < level[euler[j]] ? euler[i] : euler[j];
}

int main()
{
	int n, m, q, u, v, dist;

	level[1] = parent[1] = 0;
	while(scanf("%d", &n) && n)
	{
		for(int i = 1; i < n; ++i)
		{
			scanf("%d %d", &u, &v);

			G[u].push_back(v);
			G[v].push_back(u);
		}

		dfs(1, m = 0);
		init_st(m);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &u, &v);

			dist = level[u] + level[v] - (level[lca(idx[u], idx[v])] << 1);
			u = level[u] > level[v] ? u : v;
			v = dist >> 1;

			while(v--) u = parent[u];

			if(dist & 1)
			{
				v = parent[u];
				if(u > v) printf("The fleas jump forever between %d and %d.\n", v, u);
				else printf("The fleas jump forever between %d and %d.\n", u, v);
			}
			else printf("The fleas meet at %d.\n", u);
		}

		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}

	return 0;
}

