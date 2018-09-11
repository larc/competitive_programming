#include <cstdio>
#include <algorithm>

int main()
{
	long long n, m, a, b;
	scanf("%lld %lld %lld %lld", &n, &m, &a, &b);

	n %= m;

	printf("%lld\n", std::min(n * b, (m - n) * a));
	return 0;
}
