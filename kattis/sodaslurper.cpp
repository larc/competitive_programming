#include <cstdio>

int main()
{
	int e, f, c, ans;

	while(scanf("%d %d %d", &e, &f, &c) != EOF)
	{
		f += e;
		ans = 0;
		while(f >= c)
		{
			e = f / c;
			f = f % c + e;
			ans += e;
		}

		printf("%d\n", ans);
	}

	return 0;
}

