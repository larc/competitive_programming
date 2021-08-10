#include <cstdio>
#include <cmath>

struct point
{
	double x, y;

	point operator + (const point & p) const
	{
		return {x + p.x, y + p.y};
	}

	point operator - (const point & p) const
	{
		return {x - p.x, y - p.y};
	}

	point operator / (const double & a) const
	{
		return {x / a, y / a};
	}
};

double dot(const point & p, const point & q)
{
	return p.x * q.x + p.y * q.y;
}

double norm(const point & p)
{
	return sqrt(p.x * p.x + p.y * p.y);
}

point normal(const point & p)
{
	return point{p.y, -p.x} / norm(p);
}

double area(const point * P, const int & n)
{
	double A = 0;
	for(int i = 0; i < n - 1; ++i)
		A += P[i].x * P[i + 1].y - P[i + 1].x * P[i].y;
	A += P[n - 1].x * P[0].y - P[0].x * P[n - 1].y;
	return fabs(A) / 2.0;
}

int main()
{
	int n_cases, n, nq;
	double v, t, A, p, tans;
	point P[10000];
	point N[10000];
	point dir;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d", &n, &nq);
		for(int i = 0; i < n; ++i)
			scanf("%lf %lf", &P[i].x, &P[i].y);

		p = 0;
		for(int i = 0; i < n - 1; ++i)
		{
			N[i] = normal(P[i + 1] - P[i]);
			p += norm(P[i + 1] - P[i]);
		}
		N[n - 1] = normal(P[0] - P[n - 1]);
		p += norm(P[0] - P[n - 1]);

		tans = 0;
		dir = N[0] + N[n - 1];
		dir = dir / norm(dir);
		tans += tan(acos(dot(N[n - 1], dir))) + tan(acos(dot(N[0], dir)));
		for(int i = 1; i < n; ++i)
		{
			dir = N[i] + N[i - 1];
			dir = dir / norm(dir);
			tans += tan(acos(dot(N[i - 1], dir))) + tan(acos(dot(N[i], dir)));
		}

		A = area(P, n);

		while(nq--)
		{
			scanf("%lf %lf", &v, &t);
			printf("%lf\n", A + v * t * (2 * p + v * t * tans) / 2);
		}
	}

	return 0;
}

