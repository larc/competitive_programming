#include <cstdio>
#include <vector>

#define N 10001

std::vector<int> G[N];
bool visited[N];

int count_dfs(const int & u)
{
	int count = 0;

	visited[u] = true;
	for(const int & v: G[u])
		if(!visited[v])
			count += count_dfs(v);

	return count + 1;
}

int main()
{
	int n_cases, n, m, l, x, y;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d %d", &n, &m, &l);

		for(int i = 1; i <= n; ++i)
		{
			G[i].clear();
			visited[i] = false;
		}

		while(m--)
		{
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
		}

		m = 0;
		while(l--)
		{
			scanf("%d", &x);
			if(!visited[x])
				m += count_dfs(x);
		}

		printf("%d\n", m);
	}

	return 0;
}

