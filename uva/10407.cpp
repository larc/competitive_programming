// 10407 - Simple division

#include <cstdio>

#define N 1000

int gcd(const int & a, const int & b)
{
	if(!b) return a;
	return gcd(b, a % b);
}

int main()
{
	int num[N], n, m;

	while(scanf("%d", &n), n)
	{
		num[0] = n;
		n = 1;
		while(scanf("%d", num + n), num[n]) n++;

		m = num[1] - num[0];

		for(int i = 2; i < n; ++i)
			m = gcd(m, num[i] - num[i - 1]);

		printf("%d\n", m < 0 ? -m : m);
	}

	return 0;
}

