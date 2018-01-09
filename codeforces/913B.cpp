#include <cstdio>
#include <cstring>
#include <queue>

#define N 1001

int G[N][N];
int size[N];

bool bfs(int u)
{
	std::queue<int> q;
	q.push(u);

	int n;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		
		n = 0;
		for(int i = 0; i < size[u]; i++)
		{
			int & v = G[u][i];
			q.push(v);

			if(!size[v]) n++;
		}

		if(size[u] && n < 3) return false;
	}

	return true;
}

int main()
{
	int n, u;
	scanf("%d", &n);

	memset(size, 0, sizeof(size));
	for(int i = 1; i < n; i++)
	{
		scanf("%d", &u);
		G[u][size[u]++] = i + 1;
	}

	if(bfs(1)) printf("Yes\n");
	else printf("No\n");

	return 0;
}

