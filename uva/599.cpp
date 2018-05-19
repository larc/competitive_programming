// 599 - The Forrest for the Trees

#include <cstdio>
#include <cstring>

#define N 27

struct uf
{
	int comp[N];
	int edges[N];
	int nodes[N];

	void init()
	{
		for(int i = 0; i < N; i++)
		{
			comp[i] = i;
			nodes[i] = 1;
			edges[i] = 0;
		}
	}

	int find(const int & n)
	{
		if(comp[n] == n) return n;
		return comp[n] = find(comp[n]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y)
		{
			edges[x]++;
			return 0;
		}

		comp[y] = x;
		nodes[x] += nodes[y];
		edges[x] += edges[y] + 1;
	}

	int is_tree(const int & n)
	{
		if(comp[n] == n && nodes[n] == edges[n] + 1)
			return nodes[n];

		return 0;
	}
};

int main()
{
	uf forest;
	bool nodes[N];
	char u, v, line[64];
	int n_cases, n_trees, n_acorns;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		memset(nodes, 0, sizeof(nodes));
		forest.init();

		while(scanf("%s", line), line[0] != '*')
			forest.join(line[1] - 'A', line[3] - 'A');

		scanf("%s", line);
		for(int i = 0; line[i]; i++)
			if(line[i] != ',')
				nodes[line[i] - 'A'] = 1;

		n_trees = n_acorns = 0;
		for(int i = 0; i < N; i++) if(nodes[i])
			if(forest.is_tree(i) == 1) n_acorns++;
			else if(forest.is_tree(i)) n_trees++;

		printf("There are %d tree(s) and %d acorn(s).\n", n_trees, n_acorns);
	}

	return 0;
}

