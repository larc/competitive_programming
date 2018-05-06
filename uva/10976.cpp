// 10976 - Fractions Again?!

#include <cstdio>

#define N 10000

int main()
{
	int x, y[N], k, n;
	while(scanf("%d", &k) != EOF)
	{
		n = 0;
		for(x = k + 1; x <= k << 1; x++)
			if(!((k * x) % (x - k)))
				y[n++] = x;
				
		printf("%d\n", n);
		for(int i = 0; i < n; i++)
		{
			x = k * y[i] / (y[i] - k);
			printf("1/%d = 1/%d + 1/%d\n", k, x, y[i]);
		}

	}
	return 0;
}

