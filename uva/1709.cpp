// 1709 - Amalgamated Artichokes

#include <cstdio>
#include <cmath>
#include <algorithm>


int p, a, b, c, d;

inline float price(const int k)
{
	return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main()
{
	int n;
	float decline, smax, s;

	while(scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) != EOF)
	{
		decline = 0;

		smax = price(1);
		for(int k = 2; k <= n; ++k)
		{
			s = price(k);
			decline = std::max(decline, smax - s);
			smax = std::max(smax, s);
		}

		printf("%f\n", decline);
	}

	return 0;
}

