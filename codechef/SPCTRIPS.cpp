#include <cstdio>

int main()
{
	int n_cases, n, n_triplets;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);

		n_triplets = 0;
		for(int c = 1; c <= n; ++c)
		for(int b = 2 * c; b <= n; b += c)
			n_triplets += 1 + (n - c) / b;

		printf("%d\n", n_triplets);
	}

	return 0;
}

