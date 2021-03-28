// 6136 - Fix the Pond

#include <cstdio>

#define N 301
#define node(i, j) (i) * (n + 1) + j

struct union_find
{
	int comp[4 * N * N + 2 * N];

	void init(const int & m)
	{
		for(int i = 0; i < m; ++i)
			comp[i] = i;
	}

	int n_comp(const int & m)
	{
		int count = 0;
		for(int i = 0; i < m; ++i)
			if(comp[i] == i) count++;

		return count;
	}

	int find(const int & x)
	{
		if(comp[x] == x) return x;
		return comp[x] = find(comp[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y) return 0;

		comp[y] = x;
		return 1;
	}
};

int main()
{
	union_find uf;
	char barriers[N];

	int n, m;
	while(scanf("%d", &n) != EOF)
	{
		n <<= 1;
		m = n + n * n;
		uf.init(m);

		for(int i = 0; i + 1 < n; ++i)
		{
			scanf("%s", barriers);
			for(int j = 0; barriers[j]; ++j)
			{
				if(barriers[j] == 'H')
				{
					uf.join(node(i, (j << 1) + (i & 1)),
							node(i, (j << 1) + 1 + (i & 1))
							);
					uf.join(node(i + 1, (j << 1) + (i & 1)),
							node(i + 1, (j << 1) + 1 + (i & 1))
							);
				}
				else
				{
					uf.join(node(i, (j << 1) + (i & 1)),
							node(i + 1, (j << 1) + (i & 1))
							);
					uf.join(node(i, (j << 1) + 1 + (i & 1)),
							node(i + 1, (j << 1) + 1 + (i & 1))
							);
				}
			}
		}

		for(int i = 1; i < n; i += 2)
		{
			uf.join(node(0, i), node(0, i + 1));
			uf.join(node(n - 1, i), node(n - 1, i + 1));

			if(i + 1 < n) uf.join(node(i, 0), node(i + 1, 0));
			uf.join(node(i - 1, n), node(i, n));
		}

		printf("%d\n", uf.n_comp(m) - 1);
	}

	return 0;
}

