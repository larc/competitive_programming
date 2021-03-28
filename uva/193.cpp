// 193 - Graph Coloring

#include <cstdio>
#include <cstring>

#define N 101

int G[N][N];
int size[N];

char color[N];
int vblack[N], n_vblack;	// answer
int tmp_black[N];

void max_independent_set(const int & u, const int & idx)
{
	if(!u)
	{
		if(idx > n_vblack)
		{
			n_vblack = idx;
			memcpy(vblack, tmp_black, sizeof(int) * n_vblack);
		}
		return;
	}

	if(!color[u])
	{
		for(int i = 0; i < size[u]; ++i)
		{
			const int & v = G[u][i];
			if(!color[v]) color[v] = u;
		}

		tmp_black[idx] = u;
		max_independent_set(u - 1, idx + 1);

		for(int i = 0; i < size[u]; ++i)
		{
			const int & v = G[u][i];
			if(color[v] == u) color[v] = 0;
		}
	}

	max_independent_set(u - 1, idx);
}

int main()
{
	int m, n, k, u, v;

	scanf("%d", &m);
	while(m--)
	{
		memset(size, 0, sizeof(size));

		scanf("%d %d", &n, &k);
		while(k--)
		{
			scanf("%d %d", &u, &v);
			G[u][size[u]++] = v;
			G[v][size[v]++] = u;
		}

		memset(color, 0, sizeof(color));	// 0 if can be black

		n_vblack = 0;
		max_independent_set(n, 0);

		printf("%d\n%d", n_vblack, vblack[n_vblack - 1]);
		for(int i = n_vblack - 2; i >= 0; i--)
			printf(" %d", vblack[i]);
		putchar('\n');
	}

	return 0;
}

