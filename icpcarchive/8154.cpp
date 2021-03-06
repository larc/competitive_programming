// 8154 - Frosting on the Cake

#include <cstdio>

int main()
{
	long long A[3], B[3];
	int n, cm;

	while(scanf("%d", &n) != EOF)
	{
		A[0] = A[1] = A[2] = 0;
		B[0] = B[1] = B[2] = 0;

		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &cm);
			A[i % 3] += cm;
		}
		
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &cm);
			B[i % 3] += cm;
		}
		
		printf("%lld %lld %lld\n", A[0] * B[1] + A[1] * B[0] + A[2] * B[2],
									A[0] * B[2] + A[1] * B[1] + A[2] * B[0],
									A[0] * B[0] + A[1] * B[2] + A[2] * B[1] );
	}

	return 0;
}

