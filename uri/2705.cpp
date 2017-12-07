// 2705 - Keep It Covered
// ACM ICPC 2017 - South America

#include <cstdio>
#include <cstring>

#define N 21
#define M N * N * 2

#define pos(i, j) (i * c + j) << 1

int G[M][8];
int size[M];
bool visited[M];
int match[M];

bool augmenting_path(const int & u) // dfs: mcbm
{
	if(visited[u]) return 0;
	visited[u] = 1;
	
	int v;
	for(int i = 0; i < size[u]; i++)
	{
		v = G[u][i];
		if(match[v] == -1 || augmenting_path(match[v]))
		{
			match[v] = u;
			match[u] = v;
			return 1;
		}
	}
	
	return 0;
}

int main()
{
	char cell[N][N];
	int r, c, u, v, n, mcbm;

	auto add_edge = [&](const int & i, const int & j)
	{
		if(i < 0 || i >= r) return;
		if(j < 0 || j >= c) return;
		
		v = pos(i, j);
		G[u][size[u]++] = v;
		
		if(cell[i][j] == 'o') return;
		
		G[u][size[u]++] = v + 1;
	};

	while(scanf("%d %d", &r, &c) != EOF)
	{
		memset(size, 0, sizeof(size));

		for(int i = 0; i < r; i++)
			scanf("%s", cell[i]);
		
		n = 0;
		for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
		{
			n += cell[i][j] != 'o' ? 2 : 1;

			if((i + j) & 1)
			{
				u = pos(i, j);
				add_edge(i - 1, j);		
				add_edge(i + 1, j);		
				add_edge(i, j - 1);		
				add_edge(i, j + 1);

				if(cell[i][j] != 'o')
				{
					u++;
					add_edge(i - 1, j);		
					add_edge(i + 1, j);		
					add_edge(i, j - 1);		
					add_edge(i, j + 1);		
				}
			}
		}
		
		if(n & 1) printf("N\n");
		else
		{
			memset(match, -1, sizeof(match));
			
			mcbm = 0;
			for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				if((i + j) & 1)
				{
					u = pos(i, j);
					
					memset(visited, 0, sizeof(visited));
					mcbm += augmenting_path(u);
					
					if(cell[i][j] != 'o')
					{
						memset(visited, 0, sizeof(visited));
						mcbm += augmenting_path(u);
					}
				}
			}

			n >>= 1;
			if(mcbm == n) printf("Y\n");
			else printf("N\n");
		}
	}

	return 0;
}

