#include <cstdio>
#include <cstring>
#include <vector>

#define N 101

std::vector<int> G[N];
unsigned long long nodes[N];
int next_node[N];
bool visited[N];

int dfs(const int & u)
{
	if(visited[u]) return 0;
	
	visited[u] = 1;

	int n, next = 0, max_n = 0;
	for(const int & v: G[u])
	{
		n = dfs(v);
		if(n > max_n)
		{
			next = v;
			max_n = n;
		}
	}

	next_node[u] = next;
	return max_n + 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		scanf("%llu", nodes + i);
	
	for(int u = 1; u <= n; u++)
	for(int v = 1; v <= n; v++)
		if(	nodes[u] != nodes[v] &&
			(nodes[v] == nodes[u] << 1 || (!(nodes[u] % 3) && nodes[u] == nodes[v] * 3)) )
			G[u].push_back(v);


	for(int u = 1; u <= n; u++)
	{
		memset(visited, 0, sizeof(visited));
		if(dfs(u) == n)
		{
			while(next_node[u])
			{
				printf("%llu ", nodes[u]);
				u = next_node[u];
			}
			printf("%llu\n", nodes[u]);
			break;
		}
	}

	return 0;
}

