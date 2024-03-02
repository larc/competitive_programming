#include <cstdio>
#include <cstring>

#define N 51

int G[N][N];
int size[N];

inline bool is_eulerian()
{
	for(int i = 0; i < N; ++i)
		if(size[i] & 1) return 0;

	return 1;
}

void dfs(const int u)
{
	for(int v = 0; v < N; ++v)
	{
		if(G[u][v])
		{
			G[u][v]--;
			G[v][u]--;
			dfs(v);
			printf("%d %d\n", v, u);
		}
	}
}

int main()
{
	int t, n, u, v;

	int c = 0;
	scanf("%d", &t);
	while(t--)
	{
		memset(G, 0, sizeof(G));
		memset(size, 0, sizeof(size));

		scanf("%d", &n);
		while(n--)
		{
			scanf("%d %d", &u, &v);
			G[u][v]++;
			G[v][u]++;
			size[u]++;
			size[v]++;
		}

		printf("Case #%d\n", ++c);
		if(!is_eulerian()) printf("some beads may be lost\n");
		else dfs(u);

		if(t) printf("\n");
	}

	return 0;
}

