// 1492 - Counting ones

#include <cstdio>

typedef unsigned long long ulong_t;

inline ulong_t lg(ulong_t n)
{
	ulong_t l = 0;
	while(n >>= 1) l++;

	return l;
}

inline ulong_t S(const ulong_t & n)
{
	return (n * lg(n)) >> 1;
}

ulong_t A(const ulong_t & n)
{
	if(!n) return 0;

	ulong_t r = 1;
	return S(r <<= lg(n)) + (n - r) + A(n - r);
}

int main()
{
	ulong_t a, b;
	while(scanf("%llu %llu", &a, &b) != EOF)
		printf("%llu\n", A(b + 1) - A(a));

	return 0;
}
