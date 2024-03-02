// 11235 - Frequent values

#include <cstdio>

#define N 100001

#define L(i) (i << 1) + 1
#define R(i) (i + 1) << 1

int seq[N];			// sequence non decreasing
int freq[N];		// frequency sequence
int left[N];		// left limit of freq[i]
int tree[N << 2];	// segment tree save i-index of freq[i]

int value(const int idx, int i, int j)
{
	if(left[idx] + freq[idx] - 1 < i || j < left[idx])
		return 0;

	i = i < left[idx] ? left[idx] : i;
	j = left[idx] + freq[idx] - 1 < j ? left[idx] + freq[idx] - 1 : j;

	return j - i + 1;
}

void build(const int n, const int a, const int b)
{
	if(a == b)
	{
		tree[n] = a;
		return;
	}

	int m = (a + b) >> 1;
	build(L(n), a, m);
	build(R(n), m + 1, b);

	int l = tree[L(n)];
	int r = tree[R(n)];
	tree[n] = value(l, a, b) > value(r, a, b) ? l : r;

	tree[n] = value(m, a, b) > value(tree[n], a, b) ? m : tree[n];
}

int rmq(const int n, const int a, const int b, const int i, const int j)
{
	if(b < i || j < a) return -1;
	if(i <= a && b <= j) return tree[n];

	int m = (a + b) >> 1;
	int l = rmq(L(n), a, m, i, j);
	int r = rmq(R(n), m + 1, b, i, j);

	if(l == -1) return r;
	if(r == -1) return l;
	if(value(l, i, j) > value(r, i, j))
		return value(m, i, j) > value(l, i, j) ? m : l;
	return value(m, i, j) > value(r, i, j) ? m : r;
}

int main()
{
	int n, q, i, j;

	while(scanf("%d", &n), n)
	{
		scanf("%d", &q);
		for(int k = 1; k <= n; ++k)
			scanf("%d", &seq[k]);

		freq[1] = left[1] = 1;
		for(int k = 2; k <= n; ++k)
			if(seq[k] == seq[k - 1])
			{
				left[k] = left[k - 1];
				freq[k] = freq[k - 1] + 1;
			}
			else
			{
				left[k] = k;
				freq[k] = 1;
			}

		for(int k = n - 1; k >= 0; k--)
			if(seq[k] == seq[k + 1])
				freq[k] = freq[k + 1];

		build(0, 1, n);
		while(q--)
		{
			scanf("%d %d", &i, &j);
			printf("%d\n", value(rmq(0, 1, n, i, j), i, j));
		}
	}

	return 0;
}

