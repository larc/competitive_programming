// 8150 - Shattered Cake

#include <cstdio>

int main()
{
	int W, A, w, l, n;

	while(scanf("%d %d", &W, &n) != EOF)
	{
		A = 0;
		while(n--)
		{
			scanf("%d %d", &w, &l);
			A += w * l;
		}

		printf("%d\n", A / W);
	}

	return 0;
}

