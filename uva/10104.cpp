// 10104 - Euclid Problem

#include <cstdio>
#include <algorithm>

int ext_euclides(const int a, const int b, int & x, int & y)
{
	if(!b)
	{
		x = 1;
		y = 0;
		return a;
	}

	int d = ext_euclides(b, a % b, x, y);
	int ax = y;
	int ay = x - (a / b) * y;

	x = ax;
	y = ay;

	return d;
}

int main()
{
	int a, b, x, y, d;

	while(scanf("%d %d", &a, &b) != EOF)
	{
		d = ext_euclides(a, b, x, y);
		printf("%d %d %d\n", x, y, d);
	}

	return 0;
}

