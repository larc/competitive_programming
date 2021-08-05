#include <cstdio>

int main()
{
	int n, s, d, x, y;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &s, &d);

		x = (s + d) / 2;
		y = s - x;

		if(y < 0 || x + y != s || x - y != d)
			printf("impossible\n");
		else
			printf("%d %d\n", x, y);
	}

	return 0;
}

