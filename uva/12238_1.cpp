// 12238 - Ants Colony (Tarjan's off-line least-common-ancestors algorithm)

#include <cstdio>
#include <cstring>
#include <vector>

#define N 100000

using namespace std;

vector<int> G[N];
vector<pair<int, int> > Q[N];

int length[N];
long long dist[N];
long long query[N];
bool visited[N];
int set[N];

int find_set(const int x)
{
	if(set[x] == x) return x;
	return set[x] = find_set(set[x]);
}

void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);

	if(x != y) set[y] = x;
}

void lca(const int u)
{
	set[u] = u;

	for(const int v: G[u])
	{
		dist[v] = dist[u] + length[v];
		lca(v);
		union_set(u, v);
	}

	visited[u] = 1;

	for(auto & p: Q[u])		// v: p.first, i-th query
		if(visited[p.first])
			query[p.second] = dist[u] + dist[p.first] - (dist[find_set(p.first)] << 1);
}

int main()
{
	int n, q, u, v;

	dist[0] = length[0] = 0;
	while(scanf("%d", &n) && n)
	{
		for(int i = 1; i < n; ++i)
		{
			scanf("%d", &u);
			scanf("%d", length + i);

			G[u].push_back(i);
		}

		scanf("%d", &q);
		for(int i = 0; i < q; ++i)
		{
			scanf("%d %d", &u, &v);
			Q[u].push_back({v, i});
			Q[v].push_back({u, i});
		}

		memset(visited, 0, sizeof(visited));
		lca(0);		// compute all queries

		printf("%lld", query[0]);
		for(int i = 1; i < q; ++i)
			printf(" %lld", query[i]);

		putchar('\n');

		for(int i = 0; i < n; ++i)
		{
			G[i].clear();
			Q[i].clear();
		}
	}

	return 0;
}

