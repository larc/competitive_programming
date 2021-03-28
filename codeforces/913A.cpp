#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	if(n > 26) printf("%d\n", m);
	else printf("%d\n", m & ((1 << n) - 1));

	return 0;
}

