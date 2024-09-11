// 11689 - Soda Surpler

#include <cstdio>

int main()
{
	int n, e, f, c, ans;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d", &e, &f, &c);

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

