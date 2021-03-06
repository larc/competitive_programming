#include <cstdio>
#include <cstring>
#include <queue>

#define N 5001

int * G[N];		// adj list
int size[N];
int nivel[N];
int sort[N];
int center[N];

int bfs(int u)
{
	memset(nivel, -1, sizeof(nivel));
	std::queue<int> q;
	
		nivel[u] = 0;
		q.push(u);

	int v, k, n, s;
	n = -1;	// current nivel
	s = 0;	// sort by nivels
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		
		if(nivel[u] != n)
		{
			k = s;
			n = nivel[u];
		}

		sort[s++] = u;

		for(int i = 0; i < size[u]; ++i)
		{
			v = G[u][i];
			if(nivel[v] < 0)
			{
				nivel[v] = nivel[u] + 1;
				q.push(v);
			}
		}
	}

	return k; // nodes last nivel
}

void mark_center(int i, const int & n)
{
	int j = i >> 1;
	if(i & 1) i = j; i++;
	for(int u = 1; u <= n; ++u)
	{
		if(nivel[u] == j) center[u]++;
		if(nivel[u] == i) center[u]++;
	}
}

int main()
{
	G[0] = new int[2 * N];

	int n, u, v, k, i;
	while(scanf("%d", &n) != EOF)
	{
		i = 0;
		for(u = 1; u <= n; ++u)
		{
			scanf("%d", &k);
			size[u] = k;
			G[u] = G[0] + i;
			
			while(k--)
				scanf("%d", &G[0][i++]);
		}
		
		memset(center, 0, sizeof(center));
		
		k = bfs(sort[bfs(1)]);
		v = sort[k];
		i = nivel[v];	
		
		mark_center(i, n);
		while(k < n) center[sort[k++]] = -2;		
		
		k = bfs(v);
		mark_center(i, n);
		while(k < n) center[sort[k++]] = -2;		
		
		printf("Best Roots  :");
		for(u = 1; u <= n; ++u)
			if(center[u] == 2) printf(" %d", u);
		printf("\n");

		printf("Worst Roots :");
		for(u = 1; u <= n; ++u)
			if(center[u] < 0) printf(" %d", u);
		printf("\n");
	}

	delete [] G[0];
	return 0;
}

