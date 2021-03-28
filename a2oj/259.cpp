// 259. R2

#include <cstdio>

int main()
{
	int r1, m, n;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &r1, &m);
		printf("%d\n", (m << 1) - r1);
	}

	return 0;
}

