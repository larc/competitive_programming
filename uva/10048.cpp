#include <cstdio>
#include <cstring>
#include <queue>

#define N 101

int E[N][N];	// edges weight 

struct edge_t
{
	int a, b; // nodes
};

bool operator<(const edge_t & x, const edge_t & y)
{
	return E[x.a][x.b] > E[y.a][y.b];
}

int G[N][N];			// graph
int sG[N];
int T[N][N];			// minimum spanning tree
int sT[N];

int D[N][N];	// minimum edge in path
bool visited[N];

void prim(int n)
{
	if(visited[n]) return;

	visited[n] = 1;
	std::priority_queue<edge_t> q;

	int i, j;
	for(i = 0; i < sG[n]; i++)
	{
		j = G[n][i];
		if(!visited[j])
			q.push({n, j});
	}
	
	edge_t e;
	while(!q.empty())
	{
		e = q.top();
		q.pop();
		
		i = e.a;
		j = n = e.b;
		if(!visited[n])
		{
			visited[n] = 1;
			T[i][sT[i]++] = j;
			T[j][sT[j]++] = i;

			for(i = 0; i < sG[n]; i++)
			{
				j = G[n][i];
				if(!visited[j])
					q.push({n, j});
			}
		}
	}
}

void dfs(const int & n, int * d)
{
	if(visited[n]) return;
	visited[n] = 1;
	
	int j;
	for(int i = 0; i < sT[n]; i++)
	{
		j = T[n][i];
		if(!visited[j])
		{
			d[j] = d[n];
			if(E[n][j] > d[j]) d[j] = E[n][j];
			dfs(j, d);
		}
	}
}

int main()
{
	int n, e, q, i, j;
	int d;
	
	int c = 1;
	while(scanf("%d %d %d", &n, &e, &q), n, e, q)
	{
		memset(sG, 0, sizeof(sG));
		memset(sT, 0, sizeof(sT));

		while(e--)
		{
			scanf("%d %d %u", &i, &j, &d);
			G[i][sG[i]++] = j;
			G[j][sG[j]++] = i;

			E[i][j] = E[j][i] = d;
		}

		memset(visited, 0, sizeof(visited));
		for(i = 1; i <= n; i++)
			prim(i);
		
		memset(D, -1, sizeof(D));
		for(i = 1; i <= n; i++)
		{
			memset(visited, 0, sizeof(visited));
			dfs(i, D[i]);
		}
		
		if(c > 1) printf("\n");
		printf("Case #%d\n", c++);
		while(q--)
		{
			scanf("%d %d", &i, &j);
			if(D[i][j] != -1) printf("%u\n", D[i][j]);
			else printf("no path\n");
		}
	}

	return 0;
}

