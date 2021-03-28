#include <cstdio>
#include <cstring>
#include <vector>

#define N 200001

int component[N];
int nodes[N];
int edges[N];

void init(const int & n)
{
	for(int i = 1; i <= n; ++i)
	{
		component[i] = i;
		nodes[i] = 1;
		edges[i] = 0;
	}
}

int find_comp(const int & x)
{
	if(x == component[x]) return x;
	return component[x] = find_comp(component[x]);
}

bool join(int x, int y)
{
	x = find_comp(x);
	y = find_comp(y);

	if(x == y)
	{
		edges[x]++;
		return 0;
	}

	if(nodes[x] > nodes[y])
	{
		component[y] = x;
		nodes[x] += nodes[y];
		edges[x] += edges[y] + 1;
		return 1;
	}

	component[x] = y;
	nodes[y] += nodes[x];
	edges[y] += edges[x] + 1;
	return 1;
}

int main()
{
	int degree[N] = {};

	int n, m, v, u;
	scanf("%d %d", &n, &m);

	init(n);
	while(m--)
	{
		scanf("%d %d", &v, &u);
		degree[v]++;
		degree[u]++;

		join(v, u);
	}

	for(int i = 1; i <= n; ++i)
	{
		v = find_comp(i);
		if(edges[v] == nodes[v] && degree[i] != 2)
			edges[v] = N << 1;
	}

	m = 0;
	for(int i = 1; i <= n; ++i)
		if(component[i] == i && edges[i] == nodes[i]) m++;

	printf("%d\n", m);

	return 0;
}

