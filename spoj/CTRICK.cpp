#include <cstdio>
#include <cstring>

#define N 20001

int card[N], ft[N], n;

void adjust(int i, const int & v)
{
	while(i <= n)
	{
		ft[i] += v;
		i += i & -i;
	}
}

int rsq(int i)
{
	int r = 0;
	while(i)
	{
		r += ft[i];
		i -= i & -i;
	}
	return r;
}

int next_pos(const int & x, const int & i, const int & j)
{
	if(j < i) return i;
	int m = (i + j) >> 1;

	if(!card[m] && rsq(m) == x) return m;

	if(rsq(m) < x) return next_pos(x, m + 1, j);
	return next_pos(x, i, m - 1);
}

int main()
{
	int n_cases, p;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		memset(ft, 0, sizeof(ft));
		for(int i = 1; i <= n; ++i)
			adjust(i, 1);

		memset(card, 0, sizeof(card));

		p = 0;
		for(int i = 1; i <= n; ++i)
		{
			p = next_pos((rsq(p) + i) % (n - i + 1) + 1, 1, n);
			card[p] = i;
			adjust(p, -1);
		}

		printf("%d", card[1]);
		for(int i = 2; i <= n; ++i)
			printf(" %d", card[i]);
		putchar('\n');
	}

	return 0;
}

