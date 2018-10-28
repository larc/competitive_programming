// 6492 - Welcome Party

#include <cstdio>
#include <cstring>

#define N 27

int size[N];
int G[N][N];
bool exist[N];
int match[N];
bool visited[N];

bool aug(const int & u)
{
	if(visited[u]) return 0;
	
	visited[u] = 1;
	for(int i = 0; i < size[u]; i++)
	{
		const int & v = G[u][i];
		if(match[v] == -1 || aug(match[v]))
		{
			match[v] = u;
			return 1;
		}
	}

	return 0;
}

int main()
{
	char name[64], lastname[64];
	int n, u, v;
	
	while(scanf("%d", &n) && n)
	{
		memset(exist, 0, sizeof(exist));
		memset(size, 0, sizeof(size));
		memset(match, -1, sizeof(match));

		while(n--)
		{
			scanf("%s %s", name, lastname);
			
			u = *name - 'A';
			v = *lastname - 'A';
			exist[u] = 1;
			G[u][size[u]++] = v;
		}
	
		n = 0;
		for(u = 0; u < N; u++)
		{
			memset(visited, 0, sizeof(visited));
			if(exist[u] && aug(u)) n++;
		}

		printf("%d\n", n);
	}

	return 0;
}

