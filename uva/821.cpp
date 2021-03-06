// 821 - Page Hopping

#include <cstdio>
#include <cstring>
#include <queue>

#define N 101

int G[N][N];
int size[N];
int visited[N];

float bfs(int u)
{
	int v;
	float sum = 0;
	memset(visited, -1, sizeof(visited));
	visited[u] = 0;

	std::queue<int> q;
	q.push(u);
	
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		
		for(int i = 0; i < size[u]; ++i)
		{
			v = G[u][i];
			if(visited[v] < 0)
			{
				sum += visited[v] = 1 + visited[u];
				q.push(v);
			}
		}
	}

	return sum;
}

int main()
{
	int a, b, m, c = 1;
	float sum;

	while(scanf("%d %d", &a, &b), a && b)
	{
		memset(size, 0, sizeof(size));

		do
		{
			G[a][size[a]++] = b;
		}
		while(scanf("%d %d", &a, &b), a && b);
		
		sum = 0; m = 0;
		for(int i = 1; i <= 100; ++i)
		{
			if(size[i])
			{
				m++;
				sum += bfs(i);
			}
		}

		printf("Case %d: average length between pages = %.3f clicks\n", c++, sum / (m * (m - 1)));
	}

	return 0;
}

