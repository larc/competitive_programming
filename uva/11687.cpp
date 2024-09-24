// 11687 - Digits

#include <cstdio>

int main()
{
	char str[1000001];
	int xp, x, n, i;

	while(scanf("%s", str), str[0] != 'E')
	{
		xp = !str[1] && str[0] == '1';

		x = 0;
		while(str[++x]);

		i = 1;
		while(xp != x)
		{
			n = xp = x;

			x = 1;
			while(n /= 10) ++x;

			++i;
		}

		printf("%d\n", i);
	}

	return 0;
}

