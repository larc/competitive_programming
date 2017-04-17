#include <cstdio>
#include <algorithm>
#include <cmath>

struct point_t
{
	double x;
	double y;
	
	bool operator < (const point_t & p)
	{
		return x < p.x;
	}
};

double distance(const point_t & a, const point_t & b, double & y)
{
	if(a.y < y) return 0;

	point_t c;
	c.y = y;
	c.x = (a.x - b.x) * (y - a.y) / (a.y - b.y) + a.x;
	c.x -= a.x;
	c.y -= a.y;
	y = a.y;
	return sqrt(c.x * c.x + c.y * c.y);
}

int main()
{
	int N = 100;
	point_t points[N];
	double sum, ymax;

	int c, n;
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%lf %lf", &points[i].x, &points[i].y);

		std::sort(points, points + n);
		
		sum = 0;
		ymax = 0;
		for(int i = n - 2; i >= 0; i -= 2)
			sum += distance(points[i], points[i + 1], ymax);

		printf("%.2lf\n", sum);
	}
	return 0;
}

