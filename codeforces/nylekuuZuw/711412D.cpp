#include <cstdio>
#include <algorithm>

int div2(int n)
{
	int count = 0;
	while(!(n & 1))
	{
		n >>= 1;
		++count;
	}
	return count;
}

int main()
{
	int n, a, m = 1000000000;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &a);
		m = std::min(m, div2(a));
	}
	printf("%d\n", m);

	return 0;
}

