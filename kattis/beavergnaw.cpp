#include <cstdio>
#include <cmath>

int main()
{
	double D, V;
	while(scanf("%lf %lf", &D, &V) && D > 0 && V > 0)
		printf("%lf\n", cbrt(D * D * D - 6 * V / M_PI));

	return 0;
}

