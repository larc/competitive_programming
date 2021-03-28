#include <cstdio>

int main()
{
	int h, m, i, j, mid;

	scanf("%d:%d", &h, &m); i = h * 60 + m;
	scanf("%d:%d", &h, &m); j = h * 60 + m;

	mid = (i + j) >> 1;
	printf("%02d:%02d\n", mid / 60, mid % 60);

	return 0;
}

