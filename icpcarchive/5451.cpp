// 5451 - What Base Is This?

#include <cstdio>

#define N 36

int value(const char c)
{
	if('0' <= c && c <= '9')
		return c - '0';

	return c - 'A' + 10;
}

int to_base_10(char * str, const int b)
{
	int n = 0;

	while(*str)
	{
		n *= b;
		n += value(*str++);
	}

	return n;
}

int min_base(char * str)
{
	int b = 2;

	while(*str)
	{
		if(value(*str) >= b)
			b = value(*str) + 1;
		str++;
	}

	return b;
}

int main()
{
	char X[N], Y[N];
	int n, ix, iy, i, j;

	while(scanf("%s %s", X, Y) != EOF)
	{
		ix = min_base(X);
		iy = min_base(Y);

		for(i = ix; i <= N; ++i)
		{
			n = to_base_10(X, i);

			for(j = iy; j <= N; ++j)
				if(n == to_base_10(Y, j))
					break;

			if(j <= N) break;
		}

		if(i > N) printf("%s is not equal to %s in any base 2..36\n", X, Y);
		else printf("%s (base %d) = %s (base %d)\n", X, i, Y, j);
	}

	return 0;
}

