#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>

#define N 200


float G[N][N];

bool arbitrage(const int n)
{
	for(int i = 0; i < n; ++i)
		if(G[i][i] > 1.00001)
			return 1;

	return 0;
}


int main()
{
	int n, m, a, b;

	char sa[4], sb[4];
	std::unordered_map<std::string, int> C;

	while(scanf("%d", &n), n)
	{
		memset(G, 0, sizeof(G));
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", sa);

			C[sa] = i;
			G[i][i] = 1;
		}

		scanf("%d", &m);
		while(m--)
		{
			scanf("%s %s %d:%d", sa, sb, &a, &b);
			G[C[sa]][C[sb]] = float(b) / a;
		}

		for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			G[i][j] = std::max(G[i][j], G[i][k] * G[k][j]);

		arbitrage(n) ? printf("Arbitrage\n") : printf("Ok\n");
	}

	return 0;
}

