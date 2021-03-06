// 12442 - Forwarding Emails

#include <cstdio>
#include <cstring>

#define N 50001

bool visited[N];
int send[N], path[N];

int dfs(const int & u)
{
	if(visited[u]) return 0;

	visited[u] = 1;
	path[u] = 1 + dfs(send[u]);
	visited[u] = 0;

	return path[u];
}

int main()
{
	int n_cases, n, u, v;

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		memset(path, 0, sizeof(path));
		memset(visited, 0, sizeof(visited));

		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d %d", &u, &v);
			send[u] = v;
		}
		
		u = 0; v = 0;

		for(int i = 1; i <= n; ++i)
		{
			if(!path[i] && dfs(i) > v)
			{
				v = path[i];
				u = i;
			}
		}

		printf("Case %d: %d\n", c, u);
	}

	return 0;
}

