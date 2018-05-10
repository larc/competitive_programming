#include <cstdio>

int main()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", x % 5 ? x / 5 + 1: x / 5);

	return 0;
}

