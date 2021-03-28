#include <cstdio>

int main()
{
	int n_cases, n;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);

		if(n < 4)
		{
			printf("1\n%d", n);
			for(int i = 1; i <= n; ++i)
				printf(" %d", i);
			putchar('\n');

			continue;
		}

		printf("%d\n3 1 2 3\n", n >> 1);
		for(int i = 4; i + 1 <= n; i += 2)
			printf("2 %d %d\n", i, i + 1);

		if(!(n & 1)) printf("1 %d\n", n);
	}

	return 0;
}

