#include <cstdio>

#define N 5000000

int main()
{
	char str[N + 1];
	int n_cases, n, m, a, b;

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		scanf("%d", &n);
		scanf("%s", str);

		m = n >> 1;
		m += n & 1;

		for(int i = 0; i < n; ++i)
			str[i] -= '0';

		b = 0;
		for(int i = 0; i < m; ++i)
			b += str[i];

		a = b;
		for(int i = 0; i + m < n; ++i)
		{
			a += str[i + m] - str[i];
			if(b < a) b = a;
		}

		printf("Case #%d: %d\n", c, b);
	}

	return 0;
}

