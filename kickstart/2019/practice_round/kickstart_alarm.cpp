#include <cstdio>

#define N 1000000
#define M 1000000007

long long pow(const long long b, const long long n)
{
	if(!n) return 1;

	long long r = pow(b, n >> 1);
	r = (r * r) % M;

	return (n & 1) ? (r * b) % M : r;
}

int main()
{
	int n_cases;
	long long n, k, x, x_new, y, y_new, C, D, E1, E2, F, sum;
	long long * A = new long long[N];
	long long * sum_pow = new long long[N + 1];

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &n, &k, &x, &y, &C, &D, &E1, &E2, &F);
		x = x % F; y = y % F;
		C = C % F; D = D % F;
		E1 = E1 % F; E2 = E2 % F;

		sum = 0;
		for(int i = 0; i < n; ++i)
		{
			A[i] = (x + y) % F;
			sum = (sum + A[i] * (n - i) * k) % M;

			x_new = ((C * x) % F + (D * y) % F + E1) % F;
			y_new = ((D * x) % F + (C * y) % F + E2) % F;

			x = x_new;
			y = y_new;
		}

		for(int i = 2; i <= n; ++i)
			sum_pow[i] = ((pow(i, k + 1) - 1) * pow(i - 1, M - 2)) % M - 1;

		for(int i = 1; i < n; ++i)
			A[i] = (A[i] * (n - i)) % M;

		for(int i = n - 2; i > 0; i--)
			A[i] = (A[i] + A[i + 1]) % M;

		for(int i = 1; i < n; ++i)
			sum = (sum + (A[i] * sum_pow[i + 1]) % M) % M;

		printf("Case #%d: %lld\n", c, sum);
	}


	delete [] A;
	delete [] sum_pow;
	return 0;
}

