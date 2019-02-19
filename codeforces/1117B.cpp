#include <cstdio>
#include <algorithm>

#define N 200000

typedef unsigned long long ull_t;

int main()
{
	int a, max_1, max_2, n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	max_1 = max_2 = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if(a > max_1)
		{
			max_2 = max_1;
			max_1 = a;
		}
		else if(a > max_2)
			max_2 = a;
	}
	
	n = m / (k + 1);
	a = m % (k + 1);

	printf("%llu\n", (ull_t) n * k * max_1 + (ull_t) n * max_2 + (ull_t) a * max_1);
	
	return 0;
}

