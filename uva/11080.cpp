// 11080 - Place the Guards

#include <cstdio>
#include <cstring>

#define N 200

int G[N][N];
int size[N];
int visited[N];

int guards[2];

bool dfs(const int & u, const bool & b)
{
	visited[u] = b; guards[b]++;
	for(int i = 0; i < size[u]; i++)
	{
		const int & v = G[u][i];
		if(visited[v] == b)
			return 0;
		if(visited[v] == -1 && !dfs(v, !b))
			return 0;
	}

	return 1;
}

int check(const int & n)
{
	int min = 0;
	memset(visited, -1, sizeof(visited));

	for(int u = 0; u < n; u++)
	{
		guards[0] = guards[1] = 0;
		if(visited[u] == -1 && !dfs(u, 0))
			return -1;
		
		if(!guards[0]) min += guards[1];
		else if(!guards[1]) min += guards[0];
		else min += guards[0] < guards[1] ? guards[0] : guards[1];
	}

	return min;
}

int main()
{
	int n, m, n_cases, u, v;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		memset(size, 0, sizeof(size));
		
		scanf("%d %d", &n, &m);
		while(m--)
		{
			scanf("%d %d", &u, &v);
			G[u][size[u]++] = v;
			G[v][size[v]++] = u;
		}
		
		printf("%d\n", check(n));
	}

	return 0;
}

