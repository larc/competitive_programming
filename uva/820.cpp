#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define N 101
#define INF 1 << 31 - 1

int W[N][N]; // edges weight
int G[N][N]; // adj list
int size[N];
int path[N]; // bfs tree

int augment(const int & v, int min_edge)
{
	if(path[v] > 0)
	{
		min_edge = augment(path[v], fmin(min_edge, W[path[v]][v]));
		W[path[v]][v] -= min_edge;
		W[v][path[v]] += min_edge;
	}

	return min_edge;
}

int bfs(const int & s, const int & t)
{
	memset(path, -1, sizeof(path));
	std::queue<int> q;
	q.push(s);
	path[s] = 0;

	int u, v;
	while(!q.empty())
	{
		u = q.front();
		q.pop();

		if(u == t) break;

		for(int i = 0; i < size[u]; ++i)
		{
			v = G[u][i];
			if(W[u][v] > 0 && path[v] == -1)
			{
				path[v] = u;
				q.push(v);
			}
		}
	}

	return augment(t, INF);
}

int main()
{
	int n, s, t, c;
	int u, v, b, mf, f;

	int net = 1;
	while(scanf("%d", &n), n)
	{
		memset(size, 0, sizeof(size));
		memset(W, 0, sizeof(W));

		scanf("%d %d %d", &s, &t, &c);
		while(c--)
		{
			scanf("%d %d %d", &u, &v, &b);
			if(!W[u][v])
			{
				G[u][size[u]++] = v;
				G[v][size[v]++] = u;
			}

			W[u][v] += b;
			W[v][u] += b;
		}

		mf = 0;
		while((f = bfs(s, t)) < INF)
			mf += f;

		printf("Network %d\n", net++);
		printf("The bandwidth is %d.\n\n", mf);
	}

	return 0;
}

