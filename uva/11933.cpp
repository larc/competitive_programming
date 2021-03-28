// 11933 - Splitting Numbers

#include <cstdio>

int main()
{
	unsigned int n, a, b, c;
	while(scanf("%u", &n), n)
	{
		a = b = 0;
		c = 1;

		for(unsigned int i = 1; i <= n; i <<= 1)
		{
			if(n & i)
			{
				if(c) a |= i;
				else b |= i;
				c = !c;
			}
		}

		printf("%u %u\n", a, b);
	}

	return 0;
}

