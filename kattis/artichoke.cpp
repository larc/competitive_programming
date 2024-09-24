#include <cstdio>
#include <cmath>
#include <algorithm>


int p, a, b, c, d;

float price(const int k)
{
	return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main()
{
	int n;
	float decline, smin, smax, s;

	while(scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) != EOF)
	{
		decline = 0;

		smax = smin = price(1);
		for(int k = 2; k <= n; ++k)
		{
			s = price(k);
			if(s > smax)
			{
				smax = smin = s;
			}
			else if(s < smin)
			{
				smin = s;
				decline = std::max(decline, smax - smin);
			}
		}

		printf("%f\n", decline);
	}

	return 0;
}

