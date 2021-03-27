#include <cstdio>
#include <algorithm>

int main()
{
	int n_cases, n, cost, L[100];

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		scanf("%d %d", &n, &cost);
		for(int i = 0; i < n; ++i)
			L[i] = i + 1;
		
		for(int j, i = n - 2; cost > i && i >= 0; --i)
		{
			j = i + std::min(n - 1 - i, cost - i - 1);
			cost -= j - i + 1;
			for(int a = i, b = j; a < b; ++a, --b)
				std::swap(L[a], L[b]);
		}
		
		if(cost)
			printf("Case #%d: IMPOSSIBLE\n", c);
		else
		{
			printf("Case #%d:", c);
			for(int i = 0; i < n; ++i)
				printf(" %d", L[i]);
			putchar('\n');
		}
	}

	return 0;
}

