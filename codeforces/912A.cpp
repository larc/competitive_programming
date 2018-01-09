#include <cstdio>

int main()
{
	unsigned long long a, b, x, y, z;
	scanf("%llu %llu", &a, &b);
	scanf("%llu %llu %llu", &x, &y, &z);

	unsigned long long ra = 0;
	unsigned long long rb = 0;

	ra += 2 * x + y;
	rb += y + 3 * z;

	unsigned long long s = 0;
	s += ra > a ? ra - a : 0;
	s += rb > b ? rb - b : 0;

	printf("%llu\n", s);

	return 0;
}

