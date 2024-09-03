#include <cstdio>

#define MAX_N 1'000'000

struct union_find
{
	int sets[MAX_N];

	void init(const int n)
	{
		for(int i = 0; i < n; ++i)
			sets[i] = i;
	}

	int find(const int x)
	{
		return sets[x] == x ? x : sets[x] = find(sets[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y)
			return false;

		sets[y] = x;
		return true;
	}
};

int main()
{
	int N, Q, a, b;
	char q;

	union_find uf;

	while(scanf("%d %d", &N, &Q) != EOF)
	{
		uf.init(N);
		while(Q--)
		{
			scanf(" %c %d %d", &q, &a, &b);
			if(q == '?')
				printf("%s\n", uf.find(a) == uf.find(b) ? "yes" : "no");
			else
				uf.join(a, b);
		}
	}

	return 0;
}

