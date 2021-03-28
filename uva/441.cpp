// 441 - Lotto

#include <cstdio>

#define N 13

int ones(int n)
{
	int r = 0;
	while(n)
	{
		if(n & 1) r++;
		n >>= 1;
	}
	return r;
}

int main()
{
	int k, n, c, S[N];

	scanf("%d", &k);
	while(k)
	{
		for(int i = k - 1; i >= 0; i--)
			scanf("%d", S + i);

		n = 63 << (k - 6);
		while(n >= 63)
		{
			if(ones(n) == 6)
			{
				c = 6;
				for(int i = k - 1; i >= 0; i--)
					if(n & (1 << i))
					{
						printf("%d", S[i]);
						if(--c) putchar(' ');
					}
				printf("\n");
			}
			n--;
		}
		scanf("%d", &k);
		if(k) printf("\n");
	}

	return 0;
}

