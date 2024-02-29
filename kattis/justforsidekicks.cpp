#include <cstdio>
#include <cstring>

struct fenwick_tree
{
	int bit[200001];

	void reset()
	{
		memset(bit, 0, sizeof(bit));
	}

	void add(int i, const int v, const int n)
	{
		while(i <= n)
		{
			bit[i] += v;
			i += i & -i;
		}
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
};

int main()
{
	fenwick_tree ft[7];

	int a, b;
	int n, q, op;
	long long V[7];
	char P[200002];
	long long sum;

	while(scanf("%d %d", &n, &q) != EOF)
	{
		for(int i = 1; i < 7; ++i)
		{
			scanf("%lld", V + i);
			ft[i].reset();
		}

		scanf("%s", P + 1);
		for(int i = 1; P[i]; ++i)
			ft[P[i] - '0'].add(i, 1, n);

		while(q--)
		{
			scanf("%d %d %d", &op, &a, &b);
			switch(op)
			{
				case 1:
					ft[P[a] - '0'].add(a, -1, n);
					ft[b].add(a, 1, n);
					P[a] = b + '0';
					break;
				case 2:
					V[a] = b;
					break;
				case 3:
					sum = 0;
					for(int i = 1; i < 7; ++i)
						sum += V[i] * (ft[i].rsq(b) - ft[i].rsq(a - 1));
					printf("%lld\n", sum);
					break;
			}
		}
	}

	return 0;
}

