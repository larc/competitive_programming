#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define N 7201

int level[N];
std::vector<int> B;

int bfs(const int t)
{
	memset(level, -1, sizeof(level));
	level[0] = 0;

	std::queue<int> q;
	q.push(0);

	int t_min = 3600;

	int v, l;
	while(!q.empty())
	{
		const int u = q.front();
		q.pop();

		if(u == t) return u;
		if(u > t && u < t_min)
			t_min = u;

		l = level[u] + 1;
		for(const int b: B)
		{
			v = u + b;

			if(v < 0) v = 0;
			if(v > 3600) v = 3600;
			if(level[v] == -1)
			{
				level[v] = l;
				q.push(v);
			}
		}
	}

	return t_min;
}

int main()
{
	int n_cases, n, t;
	B.reserve(16);

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d", &n, &t);

		B.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &B[i]);

		n = bfs(t);
		printf("%d %d\n", level[n], n - t);
	}

	return 0;
}

