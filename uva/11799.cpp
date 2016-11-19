#include <cstdio>

int main()
{
	int t, n, c, max;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		max = 0;
		while(n--)
		{
			scanf("%d", &c);
			if(c > max) max = c;
		}
		printf("Case %d: %d\n", i, max);
	}
	return 0;
}
