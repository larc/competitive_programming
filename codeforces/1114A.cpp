#include <cstdio>

int main()
{
	int x, y, z;
	int a, b, c;

	scanf("%d %d %d", &x, &y, &z);
	scanf("%d %d %d", &a, &b, &c);

	if(a < x)
	{
		printf("NO\n");
		return 0;
	}

	a -= x; a += b;
	if(a < y)
	{
		printf("NO\n");
		return 0;
	}

	a -= y; a += c;
	if(a < z)
	{
		printf("NO\n");
		return 0;
	}

	printf("YES\n");

	return 0;
}

