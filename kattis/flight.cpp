#include <cstdio>
#include <cstring>
#include <vector>

#define N 2501


int E[N][2] = {};
bool disable[N] = {};

int level[N] = {};
int parent[N] = {};

std::vector<int> G[N];


inline int neig(const int u, const int e)
{
	return E[e][E[e][0] == u];
}

int dfs(const int u)
{
	int fu, fv;

	fu = u;
	for(const int e: G[u])
	{
		if(disable[e])
			continue;

		const int v = neig(u, e);
		if(level[v] < 0)
		{
			parent[v] = e;
			level[v] = level[u] + 1;

			fv = dfs(v);
			if(level[fv] > level[fu])
				fu = fv;
		}
	}

	return fu;
}

int farthest(const int u = 1)
{
	memset(level, -1, sizeof(level));
	parent[u] = level[u] = 0;

	return dfs(u);
}

int center(int & u)
{
	u = farthest(farthest(u));

	int n = level[u];
	for(int i = n >> 1; i; --i)
		u = neig(u, parent[u]);

	return n;
}

int main()
{
	int n, m, u, v, e, mu, mv, mf, x, y;

	std::vector<int> diameter;
	diameter.reserve(N);

	scanf("%d", &n);

	memset(disable, 0, sizeof(disable));
	for(int i = 1; i <= n; ++i)
		G[i].clear();

	for(int i = 1; i < n; ++i)
	{
		scanf("%d %d", &u, &v);

		E[i][0] = u;
		E[i][1] = v;
		G[u].push_back(i);
		G[v].push_back(i);
	}

	u = farthest(farthest());
	mf = level[u];

	diameter.clear();
	while(parent[u])
	{
		diameter.push_back(parent[u]);
		u = neig(u, parent[u]);
	}

	e = x = y = -1;
	for(const int i: diameter)
	{
		u = E[i][0];
		v = E[i][1];

		disable[i] = true;

		mu = center(u);
		mv = center(v);
		E[n][0] = u; 
		E[n][1] = v;

		G[u].push_back(n);
		G[v].push_back(n);

		m = std::max(mu, mv);
		mu = (mu + 1) >> 1;
		mv = (mv + 1) >> 1;
		m = std::max(m, mu + mv + 1);

		if(m <= mf)
		{
			mf = m;
			e = i;
			x = u;
			y = v;
		}

		disable[i] = false;
		G[u].pop_back();
		G[v].pop_back();
	}

	printf("%d\n", mf);
	printf("%d %d\n", E[e][0], E[e][1]);
	printf("%d %d\n", x, y);

	return 0;
}

