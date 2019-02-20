// 122. Teams

#include <cstdio>

size_t mcd(size_t a, size_t b)
{
	if(!b) return a;
	return mcd(b, a % b);
}

int main()
{
	size_t t, a, b, d;
	scanf("%ld", &t);
	while(t--)
	{
		scanf("%ld %ld", &a, &b);
		d = mcd(a, b);
		printf("%ld %ld\n", d, (a/d)*(b/d));
	}
	return 0;
}
