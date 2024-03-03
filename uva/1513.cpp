// 1513 - Movie collection

#include <cstdio>
#include <cstring>

#define N 100001

struct fenwick_tree
{
	int bit[2 * N];
	int size;

	void reset(const int n)
	{
		size = n + 1;
		memset(bit, 0, sizeof(bit));
	}

	int rsq(int i)
	{
		int sum = 0;
		while(i)
		{
			sum += bit[i];
			i -= i & -i;
		}

		return sum;
	}

	void add(int i, const int v)
	{
		while(i < size)
		{
			bit[i] += v;
			i += i & -i;
		}
	}
};

int main()
{
	fenwick_tree movies;
	int pos[N];
	int top;

	int n_cases;
	int m, r, a;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d", &m, &r);
		movies.reset(m + N);

		pos[1] = N + 1;
		for(int i = 2; i <= m; ++i)
			movies.add(pos[i] = N + i, 1);

		top = N;
		while(r--)
		{
			scanf("%d", &a);
			printf("%d%c", movies.rsq(pos[a]), r ? ' ' : '\n');

			movies.add(pos[a], -1);

			pos[a] = top;
			movies.add(top + 1, 1);
			--top;
		}
	}

	return 0;
}

