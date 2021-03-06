#include <cstdio>
#include <cmath>
#include <algorithm>

#define N 100001
#define M 17

int scores[N];
int st[M][N];

void init_st(int n)
{
	for(int j = 1; j <= n; ++j)
		st[0][j] = scores[j];
	
	for(int i = 1, k = 2; k <= n; i++, k = 1 << i)
	for(int j = 1; j + k - 1 <= n; ++j)
		st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (k >> 1)]);
}

int rmq(int a, int b)
{
	int k = log2(b - a + 1);
	return std::min(st[k][a], st[k][b - (1 << k) + 1]);
}

int main()
{
	int n_cases, n, q, a, b;

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		scanf("%d %d", &n, &q);
		for(int i = 1; i <= n; ++i)
			scanf("%d", scores + i);

		init_st(n);

		printf("Scenario #%d:\n", c);
		while(q--)
		{
			scanf("%d %d", &a, &b);
			printf("%d\n", rmq(a, b));
		}
	}

	return 0;
}

