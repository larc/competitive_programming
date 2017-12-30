// 2702 - Hard Choice
// ACM ICPC 2017 - South America

#include <cstdio>

int main()
{
	int ca, ba, pa, cr, br, pr;
	int num;
	
	while(scanf("%d %d %d", &ca, &ba, &pa) != EOF)
	{
		scanf("%d %d %d", &cr, &br, &pr);

		num = 0;
		if(ca < cr) num += cr - ca;
		if(ba < br) num += br - ba;
		if(pa < pr) num += pr - pa;

		printf("%d\n", num);
	}

	return 0;
}

