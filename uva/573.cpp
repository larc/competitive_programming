#include <cstdio>

int main()
{
	double h, u, d, f, s;
	int i;
	while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f) != EOF && h > 0)
	{
		f /= 100;
		f = f*u;
		s = 0;
		i = 0;
		while(1)
		{
			i++;
			s += u;
			if(s > h) break;
			s -= d;
			if(s < 0) break;
			u -= f;
			if(u < 0) u = 0;
		}
		if(s > h) printf("success on day %d\n", i);
		else printf("failure on day %d\n", i);
	}
	return 0;
}
