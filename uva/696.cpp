#include <cstdio>
#include <algorithm>

using namespace std;

int knights(int m, int n)
{
	if(m > n) swap(m, n);

	if(m == 1) return n;
	if(m == 2) return ((n >> 2) << 2) + ((n &= 3) < 3 ? n << 1 : 4);
	return (m * n + 1) >> 1;
}

int main()
{
	int m, n;
	while(scanf("%d %d", &m, &n) && (m || n))
	{
		printf("%d knights may be placed on a %d row %d column board.\n", knights(m, n), m, n);
	}
	return 0;
}

