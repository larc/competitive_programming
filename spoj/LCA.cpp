#include <cstdio>
#include <cstring>
#include <cmath>

#define N 1001
#define M 12	// lg 2N

int G[N][N];
int size[N];
int level[N];
int idx[N];
int euler[N << 1];

void dfs(const int & u, int & m)
{
	idx[u] = m;
	euler[m++] = u;

	for(int i = 0; i < size[u]; i++)
	{
		level[G[u][i]] = level[u] + 1;

		dfs(G[u][i], m);
		euler[m++] = u;
	}
}

int st[M][N];	// sparse table

void init_st(const int & m)
{
	for(int i = 0; i < m; i++)
		st[0][i] = i;
	
	int k;
	for(int i = 1; (1 << i) <= m; i++)
	{
		k = 1 << (i - 1);
		for(int j = 0; j + (1 << i) < m; j++)
		{
			const int & u = st[i - 1][j];
			const int & v = st[i - 1][j + k];
			st[i][j] = level[euler[u]] < level[euler[v]] ? u : v;
		}
	}
}

int rmq(const int & a, const int & b)
{
	if(a == b) return euler[a];
	if(b < a) return rmq(b, a);
	
	int k = log2(b - a + 1);

	const int & i = st[k][a];
	const int & j = st[k][b - (1 << k) + 1];

	return level[euler[i]] < level[euler[j]] ? euler[i] : euler[j];	
}

int main()
{
	int n_cases, n, m, q, u, v, root;

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; c++)
	{
		memset(size, 0, sizeof(size));
		memset(level, 0, sizeof(level));

		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &m);
			while(size[i] < m)
			{
				scanf("%d", G[i] + size[i]);
				level[G[i][size[i]++]]++;
			}
		}
		
		root = 1;
		while(root <= n && level[root]) root++;

		m = 0;
		level[root] = 0;
		dfs(root, m);
		init_st(m);

		printf("Case %d:\n", c);
		scanf("%d", &q);

		while(q--)
		{
			scanf("%d %d", &u, &v);
			printf("%d\n", rmq(idx[u], idx[v]));
		}
	}

	return 0;
}

