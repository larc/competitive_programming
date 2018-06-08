// 10696 - f91

#include <cstdio>

int main()
{
	int n;
	while(scanf("%d", &n), n)
		printf("f91(%d) = %d\n", n, n > 100 ? n - 10 : 91);
	return 0;
}

