// 10487 - Closest Sums

#include <cstdio>
#include <cmath>

#define N 1000

int A[N];

int main()
{
	int m, n, q, sum, ncase = 0;
	while(scanf("%d", &n), n)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", A + i);
		
		printf("Case %d:\n", ++ncase);

		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &q);
			sum = A[0] + A[1];
			for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(A[i] != A[j] && std::abs(A[i] + A[j] - q) < std::abs(sum - q))
					sum = A[i] + A[j];

			printf("Closest sum to %d is %d.\n", q, sum);
		}
	}

	return 0;
}

