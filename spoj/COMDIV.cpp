#include <cstdio>

int gcd(const int & a, const int & b)
{
	return !b ? a : gcd(b, a % b);
}

int count_divisors(const int & x)
{
	if(x == 1) return 1;

	int i, r = 2;
	for(i = 2; i * i < x; ++i)
		if(!(x % i)) r += 2;
	
	return r + (i * i == x);
}

int main()
{
	int n, a, b;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", count_divisors(gcd(a, b)));
	}

	return 0;
}

