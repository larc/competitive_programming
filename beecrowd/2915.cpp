// 2915 - Mount Marathon

#include <cstdio>

int main()
{
	int n, a, b, c = 1;

	scanf("%d %d", &n, &a);
	while(--n)
	{
		scanf("%d", &b);
		if(a < b) c++;
		a = b;
	}

	printf("%d\n", c);

	return 0;
}

