// 10341 - Solve It

#include <cstdio>
#include <cmath>

#define e 1e-10

int p, q, r, s, t, u;
inline double f(const double & x)
{
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) +  t * x * x + u;
}

inline bool stop(const double & y)
{
	return std::abs(y) < e;
}

int main()
{
	double a, b, x, y;
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
	{
		a = 0; b = 1;
		if(f(a) * f(b) > 0) printf("No solution\n");
		else
		{
			y = 1;
			while(!stop(y))
			{
				x = (a + b) / 2;
				y = f(x);

				if(y > 0) a = x;
				else b = x;
			}
			printf("%.4f\n", x);
		}
	}

	return 0;
}

