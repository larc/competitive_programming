#include <cstdio>
#include <cmath>

using ull = unsigned long long;

ull next(const ull & d, const ull & y)
{
	ull x = d, ny = 0;
	int n, nd = 0;
	while(ny <= y)
	{
		nd += n = log10(x) + 1;
		if(nd > 19) break;

		ny *= int(pow(10, n));
		ny += x;
		++x;
	}

	return ny > y && x - d >= 1 ? ny : 0;
}

int main()
{
	int n_cases, n;
	ull d, y, ny, min_ny;

	scanf("%d", &n_cases);
	for(int c = 0; c < n_cases; ++c)
	{
		scanf("%llu", &y);

		n = log10(y) + 1;
		min_ny = next(1, y);
		for(int i = 1; i <= (n >> 1); ++i)
		{
			d = y / pow(10, n - i);

			if(pow(10, 1) > n - i -	1)
			{
				ny = next(pow(10, i) - (n - i - 1)/i, y);
				if(ny && ny < min_ny) min_ny = ny;
			}

			ny = next(pow(10, i), y);
			if(ny && ny < min_ny) min_ny = ny;

			ny = next(d, y);
			if(ny && ny < min_ny) min_ny = ny;

			ny = next(d + 1, y);
			if(ny && ny < min_ny) min_ny = ny;
		}

		printf("Case #%d: %llu\n", c + 1, min_ny);
	}

	return 0;
}

