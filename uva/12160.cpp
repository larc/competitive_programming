// 12160 - Unlock the Lock

#include <cstdio>
#include <cstring>
#include <queue>

#define N 10000

int level[N];
int buttons[10];

int bfs(int u, const int & v, const int & n)
{
	memset(level, -1, sizeof(level));

	std::queue<int> q;
	q.push(u);
	level[u] = 0;

	int x;
	while(!q.empty())
	{
		u = q.front(); q.pop();

		if(u == v) return level[v];

		for(int i = 0; i < n; i++)
		{
			x = u + buttons[i];
			if(x >= N) x -= N;
			if(level[x] < 0)
			{
				level[x] = level[u] + 1;
				q.push(x);
			}
		}
	}

	return -1;
}

int main()
{
	int u, v, n, n_cases;

	n_cases = 1;
	while(scanf("%d %d %d", &u, &v, &n), u || v || n)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", buttons + i);

		if(bfs(u, v, n) == -1) printf("Case %d: Permanently Locked\n", n_cases++);
		else printf("Case %d: %d\n", n_cases++, level[v]);
	}

	return 0;
}

