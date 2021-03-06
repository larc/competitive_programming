#include <cstdio>
#include <algorithm>

#define N 10000

using namespace std;

struct point
{
	int x, y;

	bool operator < (const point & p) const
	{
		return x == p.x ? y < p.y : x < p.x;
	}

	bool operator != (const point & p) const
	{
		return x != p.x || y != p.y;
	}

	point operator - (const point & p) const
	{
		return {x - p.x, y - p.y};
	}

	int operator * (const point & p) const		// cross product 'z value'
	{
		return x * p.y - y * p.x;
	}

} points[N], CH[2 * N];

bool ccw(const point & p, const point & q, const point & r)
{
	return ((q - p) * (r - p)) > 0;
}

int convex_hull_andrew(int n_points)
{
	sort(points, points + n_points);

	int k = 1;
	for(int i = 1; i < n_points; ++i)
		if(points[i] != points[i - 1])
			points[k++] = points[i];

	n_points = k;
	

	k = 0;
	for(int i = 0; i < n_points; ++i)
	{
		while(k > 1 && !ccw(CH[k - 2], CH[k - 1], points[i])) --k;
		CH[k++] = points[i];
	}
	
	int t = k;
	for(int i = n_points - 2; i > 0; --i)
	{
		while(k > t && !ccw(CH[k - 2], CH[k - 1], points[i])) --k;
		CH[k++] = points[i];
	}
	
	while(k > t && !ccw(CH[k - 2], CH[k - 1], points[0])) --k;
	
	return k;
}

int main()
{
	int n;

	while(scanf("%d", &n) && n)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d %d", &points[i].x, &points[i].y);

		n = convex_hull_andrew(n);
		
		printf("%d\n", n);
		for(int i = 0; i < n; ++i)
			printf("%d %d\n", CH[i].x, CH[i].y);
	}

	return 0;
}

