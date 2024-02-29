#include <cstdio>
#include <cstring>

struct fenwick_tree
{
	long long * bit = nullptr;

	fenwick_tree()
	{
		bit = new long long[5000001];
	}

	~fenwick_tree()
	{
		delete [] bit;
	}

	void reset(const int n)
	{
		memset(bit, 0, sizeof(long long) * n);
	}

	void add(int i, const int v, const int n)
	{
		while(i <= n)
		{
			bit[i] += v;
			i += i & -i;
		}
	}

	long long rsq(int i)
	{
		long long sum = 0;
		while(i)
		{
			sum += bit[i];
			i -= i & -i;
		}
		return sum;
	}
};

int main()
{
	fenwick_tree ft;

	int idx, delta;
	int n, q;
	char op[2];

	while(scanf("%d %d", &n, &q) != EOF)
	{
		ft.reset(n + 1);
		while(q--)
		{
			scanf("%s %d", op, &idx);
			if(op[0] == '+')
			{
				scanf("%d", &delta);
				ft.add(idx + 1, delta, n);
			}
			if(op[0] == '?')
				printf("%lld\n", ft.rsq(idx));
		}
	}

	return 0;
}

