#include <cstdio>
#include <cstring>
#include <map>

#define N 2501
#define M 3 * N

std::pair<int, char> G[M][N]; // 1 - index
int size[M];
bool visited[M];

int match[N];
char op[N];

bool augmenting_path(const int & u) // dfs: mcbm
{
		if(visited[u]) return 0;

		visited[u] = 1;

		for(int i = 0; i < size[u]; ++i)
		{
			const int & v = G[u][i].first;
			if(match[v] == -1 || augmenting_path(match[v]))
			{
				match[v] = u;
				op[v] = G[u][i].second;
				return 1;
			}
		}

		return 0;
}

int main()
{
	int n, m, nm;

	long long res[M];
	std::map<long long, int> map;

	int A[N], B[N];

	auto add = [&m, &res, &map](const int & v, const char & c, const long long & r)
	{
		int & u = map[r];
		if(!u) res[u = ++m] = r;
		G[u][size[u]++] = {v, c};
	};


	while(scanf("%d", &n) != EOF)
	{
		memset(size, 0, sizeof(size));

		m = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d %d", A + i, B + i);

			add(i, '+', A[i] + B[i]);
			add(i, '-', A[i] - B[i]);
			add(i, '*', (long long) A[i] * B[i]);
		}

		memset(match, -1, sizeof(match));
		nm = 0;

		for(int u = 1; u <= m; ++u)
		{
			memset(visited, 0, sizeof(visited));
			nm += augmenting_path(u);
		}

		if(n == nm)
		{
			for(int i = 0; i < n; ++i)
				printf("%d %c %d = %lld\n", A[i], op[i], B[i], res[match[i]]);
		}
		else printf("impossible\n");

		map.clear();
	}

	return 0;
}

