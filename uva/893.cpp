#include <cstdio>

inline bool leap(size_t y)
{
	return !(y % 400) || (!(y % 4) && (y % 100));
}

inline size_t month(size_t m, size_t y)
{
	if(m == 2) return leap(y) ? 29 : 28;
	if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
	return 31;
}

int main()
{
	size_t p, d, m, y, dd, mm, yy, rd, rm;
	while(scanf("%ld %ld %ld %ld", &p, &d, &m, &y) != EOF && p && d && m && y)
	{
		yy = p/365;
		p %= 365;
		mm = p/30;
		p %= 30;
		dd = p;
		printf("%ld %ld %ld\n", dd, mm + m, yy + y);
	}
	return 0;
}
