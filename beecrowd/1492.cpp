// 1492 - Counting ones

#include <cstdio>

typedef unsigned long long ulong_t;

ulong_t lg(ulong_t n)
{
	ulong_t l = 0;
	while(n >>= 1) l++;

	return l;
}

ulong_t S(const ulong_t n)
{
	return (n * lg(n)) >> 1;
}

ulong_t A(const ulong_t n)
{
	if(!n) return 0;

	const ulong_t r = 1ull << lg(n);

	return S(r) + (n - r) + A(n - r);
}

int main()
{
	ulong_t a, b;
	while(scanf("%llu %llu", &a, &b) != EOF)
		printf("%llu\n", A(b + 1) - A(a));

	return 0;
}
