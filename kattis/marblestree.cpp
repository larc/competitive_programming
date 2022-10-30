#include <cstdio>
#include <cstring>

#define N 10001

int tree_childs[N];
int * childs[N];
int n_childs[N];
int marbles[N];
int parent[N];

int moves_dfs(const int & v)
{
	int moves = 0;
	for(int i = 0; i < n_childs[v]; ++i)
	{
		const int & u = childs[v][i];
		moves += moves_dfs(u);
		marbles[v] += marbles[u];
	}

	marbles[v] -= 1;

	return moves + (marbles[v] < 0 ? - marbles[v] : marbles[v]);
}

int main()
{
	int n, v, m, d;
	int * ptr = nullptr;

	while(scanf("%d", &n) != EOF && n)
	{
		for(int i = 1; i <= n; ++i)
			parent[i] = 0;

		ptr = tree_childs;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d %d %d", &v, &m, &d);

			childs[v] = ptr;
			n_childs[v] = d;
			marbles[v] = m;

			for(int j = 0; j < d; ++j)
			{
				scanf("%d", childs[v] + j);
				parent[childs[v][j]] = v;
			}

			ptr += d;
		}

		for(int i = 1; i <= n; ++i)
			if(!parent[i])
			{
				printf("%d\n", moves_dfs(i));
				break;
			}
	}

	return 0;
}

