// 1260 - Sales

#include <cstdio>

#define N 1000

int main()
{
	int A[N];
	int n_cases, n, sum;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", A + i);

		sum = 0;
		for(int i = 1; i < n; ++i)
		for(int k = 0; k < i; ++k)
			sum += A[k] <= A[i];

		printf("%d\n", sum);
	}

	return 0;
}

