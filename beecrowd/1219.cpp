// 1219 - Colourful Flowers

#include <cstdio>
#include <cmath>

int main()
{
	double a, b, c, s, R, r, A;
	double sunflowers, violets, roses;

	while(scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{
		s = (a + b + c) / 2;
		A = sqrt(s * (s - a) * (s - b) * (s - c)); // area triangle
		R = a * b * c / 4 / A;
		r = A / s;

		sunflowers = M_PI * R * R - A;
		roses = M_PI * r * r;
		violets = A - roses;

		printf("%.4lf %.4lf %.4lf\n", sunflowers, violets, roses);
	}

	return 0;
}
