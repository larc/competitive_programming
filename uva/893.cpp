// 893 - Y3K Problem

#include <cstdio>


bool leap(const int y)
{
	return !(y % 400) || (!(y % 4) && (y % 100));
}

int month(const int m, const int y)
{
	if(m == 2) return leap(y) ? 29 : 28;
	if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
	return 31;
}

int main()
{
	int x, d, m, y, r;
	while(scanf("%d %d %d %d", &x, &d, &m, &y), y)
	{
		r = month(m, y) - d;
		d = x > r ? 0 : d;
		while(x > r)
		{
			x -= r;
			r = month(++m, y);
			if(m == 13)
			{
				m = 1;

				r = leap(++y) ? 366 : 365;
				while(x > r)
				{
					x -= r;
					r = leap(++y) ? 366 : 365;
				}
				r = 31;
			}
		}

		printf("%d %d %d\n", d + x, m, y);
	}

	return 0;
}

