#include <cstdio>
#include <algorithm>

#define N 200000

int main()
{
	int A[N], n, max, m;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", A + i);

	std::sort(A, A + n);

	max = 0;
	for(int i = 0; i < n; ++i)
	{
		m = std::upper_bound(A, A + n, A[i] + 5) - &A[i];
		max = std::max(max, m);
	}

	printf("%d\n", max);
		
	return 0;
}

