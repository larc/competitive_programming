// 11504 - Dominos

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define N 100001

std::vector<int> G[N];
std::vector<int> top_sort;
bool visited[N];

void dfs(const int & u, const bool & ts = 0) // disable top_sort;
{
	visited[u] = 1;

	for(int & v: G[u])
		if(!visited[v]) dfs(v, ts);
	
	if(ts) top_sort.push_back(u);
}

int main()
{
	int n_cases, n, m, u, v;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d", &n, &m);
		while(m--)
		{
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}

		memset(visited, 0, sizeof(visited));

		top_sort.reserve(n);
		for(int i = 1; i <= n; ++i)
			if(!visited[i]) dfs(i, 1);
		
		memset(visited, 0, sizeof(visited));

		m = 0;
		for(int i = n - 1; i >= 0; i--)
			if(!visited[top_sort[i]]) { dfs(top_sort[i]); m++; }

		printf("%d\n", m);
		
		
		top_sort.clear();
		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}

	return 0;
}

