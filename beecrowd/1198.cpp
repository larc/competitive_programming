// 1198 - Hashmat the Brave Warrior

#include  <cstdio>

int main()
{
	long unsigned int a, b;
	while(scanf("%lu %lu", &a, &b) != EOF)
		printf("%lu\n", a > b ? a - b : b - a);

	return 0;
}

