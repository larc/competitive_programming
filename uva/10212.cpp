// 10212 - The Last Non-zero Digit

#include <cstdio>
#include <cstring>

int main()
{
	long long n, m, p;

	while(scanf("%lld %lld", &n, &m) != EOF)
	{
		p = 1;

		m = n - m;
		while(n > m)
		{
			p *= n--;
			while(p % 10 == 0) p /= 10;
			p %= 1000000000;
		}

		printf("%lld\n", p % 10);
	}

	return 0;
}

