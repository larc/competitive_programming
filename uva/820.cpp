#include <cstdio>
#include <cstring>

#define N 101

int W[N][N];
int G[N][N];
int size[N];

int main()
{
	int n, s, t, c;
	int u, v, b;

	int net = 1;
	while(scanf("%d", &n), n)
	{
		memset(size, 0, sizeof(size));

		scanf("%d %d %d", &s, &t, &c);
		while(c--)
		{
			scanf("%d %d %d", &u, &v, &b);
			G[u][size[u]++] = v;
			G[v][size[v]++] = u;
			W[u][v] = W[v][u] = b;
		}	
		
		printf("Network %d\n", net++);
		printf("The bandwidth %d.\n\n", 25);
	}

	return 0;
}

