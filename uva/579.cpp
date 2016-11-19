#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	double h, m, a, b;
	double d;
	while(scanf("%lf:%lf", &h, &m) != EOF && h)
	{
		h += m/60;
		h *= 5;
		a = max(h, m);
		b = min(h, m);
		d = min(a - b, 60 - a + b);
		d *= 6;
		printf("%.3lf\n", d);
	}
	return 0;
}
