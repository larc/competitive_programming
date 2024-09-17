// 3182 - Event Planning

#include <cstdio>

#define INF 1E9


int main()
{
	int n, b, h, w, min, p, i, a, tmp;

	while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF)
	{
		min = INF;
		while(h--)
		{
			scanf("%d", &p);
			for(i = 0; i < w; ++i)
			{
				scanf("%d", &a);
				if(a >= n)
				{
					tmp = p*n;
					if(tmp < min) min = tmp;
				}
			}
		}

		min <= b ? printf("%d\n", min) : printf("stay home\n");
	}

	return 0;
}
