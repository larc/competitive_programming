// 11526 - H(n)

#include <cstdio>

int main()
{
	int t;
	long long n, m, r, a, b;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &n);

		r = n; m = 1; a = n;
		for(int i = 2; m < n; ++i)
		{
			b = n / i;
			r += (a - b) * (i - 1) + b;
			m += (a - b) + 1;
	
			a = b;
		}

		printf("%lld\n", m == n ? r : r - a);
	}

	return 0;
}

