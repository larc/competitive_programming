// 924 - Spreading The News

#include <cstdio>
#include <cstring>
#include <queue>

#define N 2500

int G[N][N];
int size[N];
int level[N];
int boom_size[N];

int dfs(int u)
{
	memset(level, -1, sizeof(level));
	memset(boom_size, 0, sizeof(boom_size));
	level[u] = 0;
	
	std::queue<int> q;
	q.push(u);

	while(!q.empty())
	{
		u = q.front();
		q.pop();

		for(int i = 0; i < size[u]; ++i)
		{
			const int & v = G[u][i];
			if(level[v] < 0)
			{
				q.push(v);
				level[v] = level[u] + 1;
				boom_size[level[v]]++;
			}
		}
	}
	
	u = 0; // look for boom day
	for(int i = 1; boom_size[i]; ++i)
		if(boom_size[i] > boom_size[u])
			u = i;
	
	return u;
}

int main()
{
	memset(size, 0, sizeof(size));

	int n, v;

	scanf("%d", &n);
	for(int u = 0; u < n; ++u)
	{
		scanf("%d", size + u);
		for(int i = 0; i < size[u]; ++i)
			scanf("%d", G[u] + i);
	}
	
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &v);
		v = dfs(v);
		if(!v) printf("0\n");
		else printf("%d %d\n", boom_size[v], v);
	}

	return 0;
}

