// 12952 - Tri-du

#include <cstdio>

int main()
{
	int a, b;

	while(scanf("%d %d", &a, &b) != EOF)
		printf("%d\n", a > b ? a : b);\

	return 0;
}

