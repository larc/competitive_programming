// 7432 - Jumbled Communication
// note: judge is not judging this problem well

#include <cstdio>

int main()
{
	unsigned int n, x, y, b;

	while(scanf("%u", &n) != EOF)
	{
		while(n--)
		{
			scanf("%u", &x);

			y = b = 0;
			for(unsigned i = 0; i < 8; i++)
			{
				b = (x & (1 << i)) ^ b;
				y |= b;
				b <<= 1;
			}

			printf("%u", y & 255);
			if(n) putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}

