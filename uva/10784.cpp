// 10784 - Diagonal

#include <cstdio>
#include <cmath>

typedef unsigned long long ull;

ull sides(const ull n)
{
	return ceil((3 + sqrt(9 + 8 * n)) / 2);
}

int main()
{
	ull n;
	int c = 1;
	while(scanf("%llu", &n), n)
		printf("Case %d: %llu\n", c++, sides(n));

	return 0;
}

