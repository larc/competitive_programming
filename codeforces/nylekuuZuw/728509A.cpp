#include <cstdio>
#include <queue>
#include <vector>

#define N 200'001

std::vector<int> G[N];
std::vector<bool> visited(N);

bool bfs(int u)
{
	int n = 0;
	int m = 0;

	std::queue<int> q;
	q.push(u);
	visited[u] = true;

	while(!q.empty())
	{
		u = q.front();
		q.pop();
		++n;

		for(int v: G[u])
		{
			++m;
			if(!visited[v])
			{
				q.push(v);
				visited[v] = true;
			}
		}
	}
	
	m >>= 1;
	return m == n || m == n - 1;
}

bool verify(const int n)
{
	for(int u = 1; u <= n; ++u)
		if(!visited[u] && !bfs(u))
			return false;
	return true;
}

int main()
{
	int n, m, u, v;
	scanf("%d %d", &n, &m);

	while(m--)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	printf("%s\n", verify(n) ? "SI" : "NO");

	return 0;
}

