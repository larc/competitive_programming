#include <cstdio>

int main()
{
	int d, r, m, ma, rp, j;
	double p, a, i, ia, pt;

	while(scanf("%d %lf %lf %d", &d, &p, &a, &r) != EOF && d > 0)
	{
		scanf("%d %lf", &ma, &ia);
		pt = a;	
		a += p;
		rp = d;
		p = pt/d;
		while(--r)
		{	
			scanf("%d %lf", &m, &i);
			for(j = ma; j < m; ++j)
			{
				a *= (1 - ia);
//				printf("%lf - %d %lf %lf\n", ia, j, a, pt);
				if(a >= pt && j <= rp) rp = j;
				pt -= p;
			}
			ma = m;
			ia = i;
		}

		for(j = ma; j <= d; ++j)
		{
			a *= (1 - ia);
//			printf("%lf - %d %lf %lf\n", ia, j, a, pt);
			if(a >= pt && j <= rp) rp = j;
			pt -= p;
		}
		
		if(rp != 1) printf("%d months\n", rp);
		else printf("1 month\n");
	}
	return 0;
}
