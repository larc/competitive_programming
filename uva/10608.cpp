// 10608 - Friends

#include <cstdio>

struct union_find
{
	int P[30001];
	int S[30001];

	void init(const int n)
	{
		for(int i = 1; i <= n; ++i)
		{
			P[i] = i;
			S[i] = 1;
		}
	}

	int find(const int x)
	{
		return x == P[x] ? x : P[x] = find(P[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y)
			return false;

		P[y] = x;
		S[x] += S[y];

		return true;
	}
};

int main()
{
	int n_cases, n, m, x, y;
	union_find uf;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d", &n, &m);
		uf.init(n);

		while(m--)
		{
			scanf("%d %d", &x, &y);
			uf.join(x, y);
		}

		m = 0;
		for(int i = 1; i <= n; ++i)
			if(m < uf.S[i])
				m = uf.S[i];

		printf("%d\n", m);
	}

	return 0;
}

