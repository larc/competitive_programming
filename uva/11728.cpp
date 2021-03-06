#include <cstdio>
#include <cstring>
#include <cmath>

#define N 1001

int sum_divisors(const int & n)
{
	int sum = 1 + (1 != n ? n : 0);
	int _sqrt = sqrt(n);

	for(int x = 2; x <= _sqrt; ++x)
	{
		if(!(n % x))
		{
			sum += x;
			if(x * x != n) sum += n / x;
		}
	}

	return sum;
}

int main()
{
	int c = 0;
	int s;
	
	int sum_factors[N];
	memset(sum_factors, 255, sizeof(sum_factors));
	for(int i = 0; i < N; ++i)
	{
		s = sum_divisors(i);
		if(s < N) sum_factors[s] = i;
	}

	while(scanf("%d", &s) && s)
		printf("Case %d: %d\n", ++c, sum_factors[s]);

	return 0;
}

