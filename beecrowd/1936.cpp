// 1936 - Factorial

#include <cstdio>
#include <algorithm>

#define N 10


int main()
{
	int f[N];

	f[0] = 1;
	for(int i = 1; i < N; ++i)
		f[i] = i * f[i - 1];

	std::reverse(f, f + N);

	int n, k;
	while(scanf("%d", &n) != EOF)
	{
		k = 0;
		for(int x: f)
			while(x <= n)
			{
				++k;
				n -= x;
			}

		printf("%d\n", k);
	}

	return 0;
}

