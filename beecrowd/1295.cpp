// 1295 - The Closest Pair Problem

#include <cstdio>
#include <cmath>

#include <algorithm>
#include <vector>

#define INF 10000

struct point
{
	double x, y;

	point operator - (const point & p) const
	{
		return {x - p.x, y - p.y};
	}

	bool operator < (const point & p) const
	{
		return x == p.x ? y < p.y : x < p.x;
	}
};

double norm(const point & p)
{
	return sqrt(p.x * p.x + p.y * p.y);
}

double dist(const point & p, const point & q)
{
	return norm(p - q);
}

double closest_pair(std::vector<point> & P, int a, int b)
{
	if(a == b) return INF;

	int m = (a + b) >> 1;
	double min = closest_pair(P, a, m);
	min = std::min(min, closest_pair(P, m + 1, b));

	double d;
	for(int i = m; i >= a; --i)
	for(int j = m + 1; j <= b; ++j)
	{
		if((P[j].x - P[i].x) > min) break;

		d = dist(P[i], P[j]);
		if(d < min) min = d;
	}

	return min;
}

int main()
{
	std::vector<point> P;
	P.reserve(INF);

	int n;
	double d;
	while(scanf("%d", &n) != EOF && n)
	{
		P.resize(n);
		for(point & p: P)
			scanf("%lf %lf", &p.x, &p.y);

		std::sort(begin(P), end(P));
		d = closest_pair(P, 0, n - 1);
		d < INF ? printf("%.4lf\n", d)
				: printf("INFINITY\n");
	}

	return 0;
}

