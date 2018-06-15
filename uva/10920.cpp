// 10920 - Spiral Tap

#include <cstdio>

struct point
{
	long long x, y;
	point operator + (const point & p)
	{
		return {x + p.x, y + p.y};
	}
};

point coordinates(long long n, long long p)
{
	long long m, c = 0;
	while(n > 1 && p <= (m = (n - 2) * (n - 2))) { n -= 2, c++; };
	if(n == 1) return {1 + c, 1 + c};

	n--;
	p -= m + 1;
	m = p / n;
	if(m & 1)
	{
		if((m == 3 && !(n & 1)) || (m == 1 && (n & 1)))
			return {(p % n) + 2 + c, n + 1 + c};
		return {n - (p % n) + c, 1 + c};
	}

	if((m && !(n & 1) || (!m && (n & 1))))
		return {1 + c, (p % n) + 2 + c};
	return {n + 1 + c, n - (p % n) + c};
}

int main()
{
	long long n, p;
	point pos;

	while(scanf("%lld %lld", &n, &p), n && p)
	{
		pos = coordinates(n, p);
		printf("Line = %lld, column = %lld.\n", pos.x, pos.y);
	}

	return 0;
}

