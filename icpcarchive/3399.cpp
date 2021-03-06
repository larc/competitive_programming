// 3399 - Sum of Consecutive Prime Numbers

#include <cstdio>

#define N 10001

int lower_prime[N], primes[N], np;

void sieve()
{
	bool not_prime[N] = {};

	np = 0; primes[np++] = 2;
	for(long long i = 3; i < N; i += 2)
		if(!not_prime[i])
		{
			primes[np++] = i;
			for(long long j = i * i; j < N; j += i << 1)
				not_prime[j] = 1;
		}
	
	primes[np] = N;
	for(int i = 0; i < np; ++i)
	for(int j = primes[i]; j < primes[i + 1]; ++j)
		lower_prime[j] = i;
}

int main()
{
	sieve();

	int n, count, sum, i;
	while(scanf("%d", &n) && n)
	{
		i = lower_prime[n];
		count = sum = 0;

		for(int j = i; j >= 0; j--)
		{
			sum += primes[j];
			count += sum == n;

			if(sum >= n)
				sum -= primes[i--];
		}

		printf("%d\n", count);
	}

	return 0;
}

