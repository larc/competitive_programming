#include <cstdio>
#include <cstring>

char G[22][22], land;
int m, n, x, y;

int move(int i, int j)
{
	if(G[i][j] != land) return 0;
	G[i][j] = 0;
	return ((i == x && j == y) ? -1000 : 1) + move(i + 1, j) + move(i - 1, j) + move(i, j == n ? 1 : j + 1) + move(i, j == 1 ? n : j - 1);
}

int main()
{
	int i, j, max, aux;
	char c;
	while(scanf("%d %d", &m, &n) != EOF)
	{
		memset(G, 0, sizeof(G));
		for(i = 1; i <= m; i++)
			for(j = 0; j <= n; j++)
			{
				scanf("%c", &c);
				G[i][j] = c;
			}
				
		scanf("%d %d", &x, &y);
		x++, y++;
		land = G[x][y];

		max = 0;
		for(i = 1; i <= m; i++)
			for(j = 0; j <= n; j++)
			{
				aux = move(i, j);
				if(aux > max) max = aux;
			}
		
		printf("%d\n", max);
	}
	return 0;
}
