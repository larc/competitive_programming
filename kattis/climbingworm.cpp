#include <cstdio>

int main()
{
	int a, b, h;

	scanf("%d %d %d", &a, &b, &h);

	h = a > h ? 0 : h - a;
	printf("%d\n", 1 + (h + a - b - 1) / (a - b));

	return 0;
}

