#include <cstdio>

#define N 200001

typedef unsigned long long ull;

ull gcd(const ull & a, const ull & b)
{
	return !b ? a : gcd(b, a % b);
}

int main()
{
	ull a[N], n, z, y, max;

	scanf("%llu", &n);

	max = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%llu", a + i);
		max = a[i] > max ? a[i] : max;
	}
	
	for(int i = 0; i < n; ++i)
		a[i] = max - a[i];

	z = a[0];
	for(int i = 1; i < n; ++i)
		z = gcd(a[i], z);

	y = 0;
	for(int i = 0; i < n; ++i)
		y += a[i] / z;
	
	printf("%llu %llu\n", y, z);

	return 0;
}

