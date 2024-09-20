// 12862 - Intrepid Climber

#include <cstdio>
#include <cstring>
#include <vector>

#define N 100001


std::vector<std::pair<int, int> > G[N];
bool friends[N];
int max_cost[N];

int dfs(const int u)
{
	int e, cost, energy = 0;

	for(const auto & p: G[u])
	{
		const int v = p.first;
		const int c = p.second;

		e = dfs(v);
		cost = (e || friends[v]) ? c : 0;
		energy += e + cost;
		max_cost[u] = std::max(max_cost[u], max_cost[v] + cost);
	}

	return energy;
}

int main()
{
	int n, nf, u, v, c;

	while(scanf("%d %d", &n, &nf) != EOF)
	{
		memset(friends, 0, sizeof(friends));
		memset(max_cost, 0, sizeof(max_cost));

		for(int i = 1; i < n; ++i)
		{
			scanf("%d %d %d", &u, &v, &c);
			G[u].push_back({v, c});
		}

		while(nf--)
		{
			scanf("%d", &u);
			friends[u] = 1;
		}

		printf("%d\n", dfs(1) - max_cost[1]);

		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}

	return 0;
}

