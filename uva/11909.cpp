// 11909 - Soya Milk

#include <cstdio>
#include <cmath>

int main()
{
	double l, w, h, theta, hh;
	while(scanf("%lf %lf %lf %lf", &l, &w, &h, &theta) != EOF)
	{
		theta *= M_PI / 180;
		hh = l * tan(theta);

		if(hh > h)
			printf("%.3lf mL\n", w * h * h * tan(M_PI / 2 - theta) / 2);
		else
			printf("%.3lf mL\n", l * w * ( h - hh / 2));
	}

	return 0;
}

