// 1299 - Game of Tiles

#include <iostream>
#include <cstring>

#define N 51
#define M N * N

int G[M][4];
int size[M];
bool visited[M];
int match[M];

bool augmenting_path(const int u) // dfs: mcbm
{
		if(visited[u]) return 0;

		visited[u] = 1;

		int v;
		for(int i = 0; i < size[u]; ++i)
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
	int r, c, n, u, v, mcbm;
	char board[N][N];

	auto add_edge = [&](const int i, const int j)
	{
		if(i < 0 || i >= r) return;
		if(j < 0 || j >= c) return;
		if(board[i][j] != '.') return;

		v = i * c + j;
		G[u][size[u]++] = v;
	};

	while(scanf("%d %d", &r, &c) != EOF)
	{
		for(int i = 0; i < r; ++i)
			scanf("%s", board[i]);

		memset(size, 0, sizeof(size));

		n = 0;
		for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
		{
			u = i * c + j;
			if(board[i][j] == '.')
			{
				n++;
				if((i + j) & 1) // bipartite graph edges: black -> white cells
				{
					add_edge(i - 1, j);
					add_edge(i + 1, j);
					add_edge(i, j - 1);
					add_edge(i, j + 1);
				}
			}
			else size[u] = -1;
		}

		if(n & 1) printf("1\n");
		else
		{
			memset(match, -1, sizeof(match));

			mcbm = 0;
			for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
			{
				u = i * c + j;
				if(((i + j) & 1) && size[u] > 0 && match[u] == -1)
				{
					memset(visited, 0, sizeof(visited));
					mcbm += augmenting_path(u);
				}
			}

			n >>= 1;
			if(mcbm == n) printf("2\n"); // perfect matching
			else printf("1\n");
		}
	}

	return 0;
}

