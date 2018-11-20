// 2903 - A Symmetrical Pizza

#include <cstdio>

int gcd(int a, int b)
{
	if(!b) return a;

	return gcd(b, a % b);
}

int main()
{
	int x, y;
	scanf("%d.%d", &x, &y);
	
	x = x * 100 + y;
	printf("%d\n", 36000 / gcd(36000, x));

	return 0;
}

