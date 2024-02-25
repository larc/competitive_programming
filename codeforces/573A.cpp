#include <cstdio>

#define N 100000

int gcd(const int a, const int b)
{
	return b ? gcd(b, a % b) : a;
}

bool is_div_two_tree(int x)
{
	while(!(x & 1)) x >>= 1;
	while(!(x % 3)) x /= 3;

	return x == 1;
}

int main()
{
	int num[N], n;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", num + i);

	int d = gcd(num[0], num[1]);
	for(int i = 2; i < n; ++i)
		d = gcd(d, num[i]);

	int d23 = 0;
	for(int i = 0; i < n; ++i)
		d23 += is_div_two_tree(num[i] / d);

	if(d23 == n) printf("Yes\n");
	else printf("No\n");

	return 0;
}

