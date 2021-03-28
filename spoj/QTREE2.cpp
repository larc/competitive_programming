#include <cstdio>
#include <vector>

#define N 10001

std::vector<std::pair<int, int> > G[N];

int level[N], parent[N], dist[N], heavy[N];
int head[N], pos[N], ipos[N], current_pos;

int dfs(const int & u)
{
	heavy[u] = 0;

	int max_size = 0, size = 0, v_size;
	for(auto & p: G[u])
	{
		const int & v = p.first;
		const int & w = p.second;

		if(v != parent[u])
		{
			level[v] = level[u] + 1;
			dist[v] = dist[u] + w;
			parent[v] = u;

			size += v_size = dfs(v);
			if(v_size > max_size)
			{
				max_size = v_size;
				heavy[u] = v;
			}
		}
	}

	return size + 1;
}

void hld(const int & u, const int & h)
{
	head[u] = h;
	ipos[current_pos] = u;
	pos[u] = current_pos++;

	if(heavy[u]) hld(heavy[u], h);

	for(auto & p: G[u])
	{
		const int & v = p.first;
		const int & w = p.second;

		if(v != parent[u] && v != heavy[u])
			hld(v, v);
	}
}

int lca(int a, int b)
{
	while(head[a] != head[b])
	{
		if(level[head[b]] < level[head[a]])
			std::swap(a, b);

		b = parent[head[b]];
	}

	return level[a] < level[b] ? a : b;
}

// up to kth starting in 0
int kth(const int & a, const int & k)
{
	if(k <= pos[a] - pos[head[a]])
		return ipos[pos[a] - k];

	return kth(parent[head[a]], k - pos[a] + pos[head[a]] - 1);
}

int kth(const int & a, const int & b, const int & k)
{
	int r = lca(a, b);

	if(k <= level[a] - level[r])
		return kth(a, k);

	return kth(b, level[a] + level[b] - (level[r] << 1) - k);
}

int main()
{
	char str[5];
	int n_cases, n, u, v, w;

	level[1] = parent[1] = dist[1] = 0;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		for(int i = 1; i < n; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}

		current_pos = 0;
		dfs(1); hld(1, 1);

		while(scanf("%s", str) && str[1] != 'O')	// DONE
		{
			if(str[1] == 'I')	// DIST
			{
				scanf("%d %d", &u, &v);
				printf("%d\n", dist[u] + dist[v] - (dist[lca(u, v)] << 1));
			}
			else	// KTH
			{
				scanf("%d %d %d", &u, &v, &w);
				printf("%d\n", kth(u, v, w - 1));
			}
		}

		putchar('\n');

		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}

	return 0;
}

