#include <cstdio>
#include <algorithm>

int main()
{
	int n, x, y, a, b, d, m;

	x = y = 0; d = 1;

	scanf("%d\n", &n);
	while(n--)
	{
		scanf("%d %d", &a, &b);

		m = std::min(a, b) - std::max(x, y);
		if(m >= 0) d += m + (x != y);

		x = a; y = b;
	}

	printf("%d\n", d);

	return 0;
}
