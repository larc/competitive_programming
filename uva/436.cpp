// 436 - Arbitrage (II)

#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>

#define N 30


float G[N][N];

bool arbitrage(const int n)
{
	for(int k = 0; k < n; ++k)
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j)
	{
		G[i][j] = std::max(G[i][j], G[i][k] * G[k][j]);
		if(i == j && G[i][i] > 1.00001)
			return 1;
	}

	return 0;
}

int main()
{
	int n, m;
	float r;

	char a[32], b[32];
	std::unordered_map<std::string, int> C;

	int n_cases = 0;
	while(scanf("%d", &n), n)
	{
		memset(G, 0, sizeof(G));
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", a);

			C[a] = i;
			G[i][i] = 1;
		}

		scanf("%d", &m);
		while(m--)
		{
			scanf("%s %f %s", a, &r, b);
			G[C[a]][C[b]] = r;
		}

		printf("Case %d: %s\n", ++n_cases, arbitrage(n) ? "Yes" : "No");
	}

	return 0;
}

