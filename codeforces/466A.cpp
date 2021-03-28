#include <cstdio>

int main()
{
	int n, m, a, b;
	scanf("%d %d %d %d", &n, &m, &a, &b);

	int r, min = n * a;

	r = ((n + m) / m) * b;
	if(min > r) min = r;

	r = (n / m) * b + (n % m) * a;
	if(min > r) min = r;

	printf("%d\n", min);

	return 0;
}

