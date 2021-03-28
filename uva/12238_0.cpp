// 12238 - Ants Colony (sparse table O(n lg(n) + n)

#include <cstdio>
#include <cmath>
#include <vector>

#define N 100000
#define M 18

using namespace std;

vector<int> G[N];
int length[N];
long long dist[N];

int idx[N], euler[N << 1];	// euler tour
int st[M][N << 1];			// sparse table

void dfs(const int & u, int & m)
{
	idx[u] = m;
	euler[m++] = u;

	for(const int & v: G[u])
	{
		dist[v] = dist[u] + length[v];

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
			st[i][j] = dist[euler[u]] < dist[euler[v]] ? u : v;
		}
	}
}

int lca(const int & a, const int & b)
{
	if(b < a) return lca(b, a);

	int k = log2(b - a + 1);

	const int & i = st[k][a];
	const int & j = st[k][b - (1 << k) + 1];

	return dist[euler[i]] < dist[euler[j]] ? euler[i] : euler[j];
}

int main()
{
	int n, m, q, u, v;

	dist[0] = length[0] = 0;
	while(scanf("%d", &n) && n)
	{
		for(int i = 1; i < n; ++i)
		{
			scanf("%d", &u);
			scanf("%d", length + i);

			G[u].push_back(i);
		}

		dfs(0, m = 0);
		init_st(m);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &u, &v);
			printf("%lld", dist[u] + dist[v] - (dist[lca(idx[u], idx[v])] << 1));
			if(q) putchar(' ');
		}

		putchar('\n');

		for(int i = 0; i < n; ++i)
			G[i].clear();
	}

	return 0;
}

