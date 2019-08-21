#include <cstdio>

#define pow2(i) (1 << i)

int main()
{
	int n, l, r;
	
	scanf("%d %d %d", &n, &l, &r);
	
	printf("%d %d\n", pow2(l) - 1 + (n - l), pow2(r) - 1 + (n - r) * pow2(r - 1));

	return 0;
}

