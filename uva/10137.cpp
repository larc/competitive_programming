// 10137 - The Trip

#include <cstdio>
#include <cmath>

#define N 1000

int main()
{
	double spent[N], net, pdiff, ndiff, d;
	int n;

	while(scanf("%d", &n), n)
	{
		net = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%lf", spent + i);
			net += spent[i];
		}
		
		net /= n;

		pdiff = ndiff = 0;
		for(int i = 0; i < n; ++i)
		{
			d = (double) (long) ((spent[i] - net) * 100) / 100;
			if(d < 0) ndiff -= d;
			else pdiff += d;
		}
		
		printf("$%.2lf\n", ndiff > pdiff ? ndiff : pdiff);
	}

	return 0;
}

