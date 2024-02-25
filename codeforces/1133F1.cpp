#include <cstdio>
#include <vector>
#include <queue>

#define N 200001

int main()
{
	std::vector<int> G[N];
	bool visited[N] = {};
	int degree[N] = {};
	int n, m, u, v;

	scanf("%d %d", &n, &m);

	while(m--)
	{
		scanf("%d %d", &u, &v);

		degree[u]++; degree[v]++;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	u = 1;
	for(int i = 2; i <= n; ++i)
		if(degree[i] > degree[u])
			u = i;

	std::queue<int> q;
	visited[u] = 1;
	q.push(u);

	while(!q.empty())
	{
		u = q.front(); q.pop();
		for(const int v: G[u])
			if(!visited[v])
			{
				printf("%d %d\n", u, v);
				q.push(v);
				visited[v] = 1;
			}
	}

	return 0;
}

