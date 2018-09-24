#include <cstdio>
#include <algorithm>

#define N 200001

int main()
{	
	unsigned long long A[N], K[N], n, q, j;
	A[0] = K[0] = 0;

	scanf("%llu %llu", &n, &q);

	for(unsigned i = 1; i <= n; i++)
	{
		scanf("%llu", A + i);
		A[i] += A[i - 1];
	}
	
	for(int i = 1; i <= q; i++)
	{
		scanf("%llu", K + i);
		K[i] += K[i - 1] < A[n] ? K[i - 1] : 0;

		if(K[i] >= A[n]) printf("%llu\n", n);
		else printf("%ld\n", A + n - std::upper_bound(A, A + n + 1, K[i]) + 1);
	}

	return 0;
}

