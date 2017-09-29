// 10684 - The jackpot

#include <cstdio>

int main()
{
	int n, b, max, s;
	while(scanf("%d", &n), n)
	{
		s = max = 0;
		while(n--)
		{
			scanf("%d", &b);

			if(s < 0) s = 0;	
			s += b;
			if(s > max) max = s;
		}
		

		if(max) printf("The maximum winning streak is %d.\n", max);
		else printf("Losing streak.\n");
	}

	return 0;
}

