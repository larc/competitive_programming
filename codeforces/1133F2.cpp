#include <cstdio>
#include <vector>
#include <queue>

#define N 200001

std::vector<int> G[N];

struct union_find
{
	int comp[N];

	void init(const int & n)
	{
		for(int i = 1; i <= n; ++i)
			comp[i] = i;
	}

	int find(const int & x)
	{
		return x == comp[x] ? x : comp[x] = find(comp[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y) return 0;

		comp[y] = x;
		return 1;
	}

	int n_comp(const int & n)
	{
		int nc = 0;
		for(int i = 1; i <= n; ++i)
			nc += i == comp[i];

		return nc;
	}

} uf;

int main()
{
	bool visited[N] = {};
	int degree[N] = {};
	int n, m, d, u, v;

	scanf("%d %d %d", &n, &m, &d);

	uf.init(n);
	while(m--)
	{
		scanf("%d %d", &u, &v);
		
		degree[u]++; degree[v]++;
		G[u].push_back(v);
		G[v].push_back(u);

		if(u != 1 && v != 1)
			uf.join(u, v);
	}

	if(degree[1] < d)
	{
		printf("NO\n");
		return 0;
	}
	
	std::queue<int> q;
	visited[1] = 1;

	for(const int & v: G[1])
		if(uf.join(1, v))
		{
			q.push(v);
			visited[v] = 1;
		}

	if(q.size() > d)
	{
		printf("NO\n");
		return 0;
	}
	
	for(const int & v: G[1])
	{
		if(q.size() == d) break;
		if(!visited[v])
		{
			q.push(v);
			visited[v] = 1;
		}
	}
	
	if(q.size() != d)
	{
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	for(int i = 0; i < d; ++i)
	{
		v = q.front(); q.pop();
		printf("1 %d\n", v);
		q.push(v);
	}

	while(!q.empty())
	{
		u = q.front(); q.pop();
		for(const int & v: G[u])
			if(!visited[v])
			{
				printf("%d %d\n", u, v);
				q.push(v);
				visited[v] = 1;
			}
	}

	return 0;
}

