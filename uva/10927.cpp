#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool p_sort;

struct pole_t
{
	bool h;
	double a;
	double d;
	int x, y, z;

	pole_t(const int & x_ = 0, const int & y_ = 0, const int & z_ = 0)
	{
		h = 0;
		x = x_; y = y_; z = z_;
		a = atan2(y_, x_);
		d = hypot(x_, y_);
	}
	bool operator<(const pole_t & p)
	{
		if(p_sort)
		{
			if(h == p.h)
			{
				if(x == p.x) return y < p.y;
				return x < p.x;
			}
			return h > p.h;
		}

		if(a == p.a) return d < p.d;
		return a < p.a;
	}
};

int main()
{
	pole_t * poles = new pole_t[100000];
	int x, y, z;
	int height;

	int n, nh;
	int ds = 0;
	while(scanf("%d", &n) != EOF && n)
	{
		ds++;
		nh = 0;
		p_sort = 0;

		for(int i = 0; i < n; ++i)
		{
			scanf("%d %d %d", &x, &y, &z);
			poles[i] = pole_t(x, y, z);
		}

		sort(poles, poles + n);

		height = poles[0].z;
		for(int i = 1; i < n; ++i)
		{
			if(poles[i - 1].a == poles[i].a && poles[i].z <= height)
			{
				poles[i].h = 1;
				nh++;
			}
			else height = poles[i].z;
		}

		printf("Data set %d:\n", ds);
		if(nh)
		{
			p_sort = 1;
			sort(poles, poles + n);
			nh--;
			printf("Some lights are not visible:\n");
			for(int i = 0; i < nh; ++i)
				printf("x = %d, y = %d;\n", poles[i].x, poles[i].y);
			printf("x = %d, y = %d.\n", poles[nh].x, poles[nh].y);
		}
		else printf("All the lights are visible.\n");

	}

	delete [] poles;
	return 0;
}

