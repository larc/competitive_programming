#include <cstdio>
#include <algorithm>

int main()
{
	int n_cases, n, cost, L[100];

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", L + i);

		cost = 0;
		for(int i = 0; i < n - 1; ++i)
		for(int j = i; j < n; ++j)
			if(L[j] == i + 1)
			{
				cost += j - i + 1;
				for(int a = i, b = j; a < b; ++a, --b)
					std::swap(L[a], L[b]);

				break;
			}

		printf("Case #%d: %d\n", c, cost);
	}

	return 0;
}

