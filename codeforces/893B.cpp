#include <cstdio>

int main()
{
	int n, k, p, m;
	while(scanf("%d", &n) != EOF)
	{
		k = 1;
		p = 1;

		while(p <= n)
		{
			if(!(n % p)) m = p;
			p = ((1 << k) - 1) * (1 << (k - 1));
			k++;
		}

		printf("%d\n", m);
	}

	return 0;
}

