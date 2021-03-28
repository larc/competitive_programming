#include <cstdio>

struct point_t
{
	double x;
	double y;

	point_t(const double & x_ = 0, const double & y_ = 0)
	{
		x = x_; y = y_;
	}

	// dot product
	double operator,(const point_t & p)
	{
		return x * p.x + y * p.y;
	}

	point_t operator+(const point_t & p)
	{
		return point_t(x + p.x, y + p.y);
	}

	point_t operator-(const point_t & p)
	{
		return point_t(x - p.x, y - p.y);
	}
};

point_t operator*(const double & alpha, const point_t & p)
{
	return point_t(alpha * p.x, alpha * p.y);
}

inline double distance(point_t a, const point_t & b)
{
	a = a - b;
	return (a, a);
}

int main()
{
	double dist, d, alpha;
	point_t m, a, b, x, dx;
	size_t n;
	while(scanf("%lf %lf %ld", &m.x, &m.y, &n) != EOF)
	{
		scanf("%lf %lf", &b.x, &b.y);
		dist = distance(b, m);
		dx = b;
		while(n--)
		{
			a = b;
			scanf("%lf %lf", &b.x, &b.y);
			a = a - b;
			alpha = ( a, (m - b) ) / (a, a);
			if(alpha < 0) x = b;
			else if(alpha > 1) x = a + b;
			else x = alpha * a + b;

			d = distance(x , m);
			if(d < dist)
			{
				dist = d;
				dx = x;
			}
		}
		printf("%.4lf\n%.4lf\n", dx.x, dx.y);
	}

	return 0;
}

