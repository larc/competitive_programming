// 4104 - MODEX

#include <cstdio>

int pow_mod(const int & x, const int & y, const int & n)
{
	if(!y) return 1;

	int z = pow_mod(x, y >> 1, n);
	z *= z;
	z %= n;

	if(y & 1) z *= x;
	return z % n;
}

int main()
{
	int c, x, y, z, n;

	scanf("%d", &c);
	while(c--)
	{
		scanf("%d %d %d", &x, &y, &n);
		printf("%d\n", pow_mod(x, y, n));
	}
	scanf("%d", &c);

	return 0;
}

