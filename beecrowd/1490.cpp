// 1490 - Attacking rooks

#include <cstdio>
#include <cstring>
#include <vector>

#define N 102
#define M N * N

std::vector<int> G[M];
bool visited[M];
int match[M];

bool augmenting_path(const int u) // dfs: mcbm
{
	if(visited[u]) return 0;

	visited[u] = 1;

	for(const int v: G[u])
		if(match[v] == -1 || augmenting_path(match[v]))
		{
			match[v] = u;
			match[u] = v;
			return 1;
		}

	return 0;
}

int main()
{
	char line[N];
	int row[N], col[N];
	int n, r, c;

	for(int i = 0; i < M; ++i)
		G[i].reserve(M);

	while(scanf("%d", &n) != EOF)
	{
		memset(row, -1, sizeof(row));
		memset(col, -1, sizeof(col));

		r = 0;
		c = M / 2;
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", line);
			for(int j = 0; j < n; ++j)
			{
				if(line[j] == 'X')
				{
					row[i] = -1;
					col[j] = -1;
				}
				else
				{
					if(row[i] == -1) row[i] = r++;
					if(col[j] == -1) col[j] = c++;

					G[row[i]].push_back(col[j]);
				}
			}
		}

		memset(match, -1, sizeof(match));
		n = 0;

		for(int u = 0; u < r; ++u)
			if(match[u] == -1)
			{
				memset(visited, 0, sizeof(visited));
				n += augmenting_path(u);
			}

		printf("%d\n", n);

		for(int i = 0; i < M; ++i)
			G[i].clear();
	}

	return 0;
}

