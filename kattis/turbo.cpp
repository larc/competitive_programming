#include <cstdio>
#include <cstring>

#define N 100001


struct fenwick_tree
{
	int bit[N];
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
	fenwick_tree sort[2];

	int pos[N];
	int n, x;

	scanf("%d", &n);
	sort[0].reset(n);
	sort[1].reset(n);

	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		pos[x] = i;
		sort[0].add(i, 1);
		sort[1].add(i, 1);
	}

	sort[0].add(1, -1);
	sort[1].add(1, -1);

	for(int i = 0; i < n; ++i)
	{
		x = pos[(i & 1) ? n - (i >> 1) : (i >> 1) + 1];
		printf("%d\n", sort[i & 1].rsq(i & 1 ? n - x + 1 : x));

		sort[0].add(x, -1);
		sort[1].add(n - x + 1, -1);
	}

	return 0;
}

