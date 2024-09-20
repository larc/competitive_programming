// 1751 - Intrepid Climber

#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>

#define N 100001


std::vector<std::pair<int, int> > G[N];
bool friends[N];

std::pair<int, int> dfs(const int u, const int p = 0)
{
	int energy = 0, max_e = 0;

	for(const auto & v: G[u])
	{
		if(v.first == p) continue;

		auto e = dfs(v.first, u);
		energy += e.first + (e.first || friends[v.first]) * v.second;
		max_e = std::max(max_e, e.second + (e.second || friends[v.first]) * v.second);
	}

	return {energy, max_e};
}

int main()
{
	int n, nf, u, v, c;

	while(scanf("%d %d", &n, &nf) != EOF)
	{
		memset(friends, 0, sizeof(friends));

		for(int i = 1; i < n; ++i)
		{
			scanf("%d %d %d", &u, &v, &c);
			G[u].push_back({v, c});
			G[v].push_back({u, c});
		}

		while(nf--)
		{
			scanf("%d", &u);
			friends[u] = 1;
		}

		auto e = dfs(1);
		printf("%d\n", e.first - e.second);

		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}

	return 0;
}

