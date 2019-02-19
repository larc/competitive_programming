#include <cstdio>
#include <algorithm>

int main()
{
	int q;
	long long n, a, b, m;
	
	scanf("%d", &q);
	while(q--)
	{
		scanf("%lld %lld %lld", &n, &a, &b);
		printf("%lld\n", std::min(n * a, n / 2 * b + (n & 1) * a));
	}

	return 0;
}

