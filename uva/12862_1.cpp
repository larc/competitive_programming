// 12862 - Intrepid Climber

#include <cstdio>
#include <cstring>
#include <vector>

#define N 100001


int P[N] = {};	// parent
int C[N] = {};	// cost
int cost[N];

int climb(const int u)
{
	if(u == 1) return 0;
	if(cost[u]) return 0;

	const int p = climb(P[u]);
	cost[u] = C[u] + cost[P[u]];

	return C[u] + p;
}

int main()
{
	int n, nf, u, v, c;

	while(scanf("%d %d", &n, &nf) != EOF)
	{
		memset(cost, 0, sizeof(cost));

		for(int i = 1; i < n; ++i)
		{
			scanf("%d %d %d", &u, &v, &c);
			P[v] = u;
			C[v] = c;
		}

		n = 0; c = 0;
		while(nf--)
		{
			scanf("%d", &u);
			n += climb(u);
			c = std::max(c, cost[u]);
		}

		printf("%d\n", n - c);
	}

	return 0;
}

