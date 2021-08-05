// 2006 - Identifying tea

#include <cstdio>

int main()
{
	int t, r, a;

	while(scanf("%d", &t) != EOF)
	{
		r = 0;
		for(int i = 0; i < 5; ++i)
		{
			scanf("%d", &a);
			r += a == t;
		}

		printf("%d\n", r);
	}

	return 0;
}

