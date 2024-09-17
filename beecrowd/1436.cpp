// 1436 - Brick Game

#include <cstdio>

#define N 11

int main()
{
	int ages[N];
	int n_cases, n;

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", ages + i);

		printf("Case %d: %d\n", c, ages[n >> 1]);
	}

	return 0;
}

