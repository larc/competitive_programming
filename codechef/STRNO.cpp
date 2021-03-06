#include <cstdio>

#define N 100000

long long primes[N], np;

void sieve()
{
	bool not_prime[N] = {};

	np = 0;
	primes[np++] = 2;

	for(long long i = 3; i < N; i += 2)
		if(!not_prime[i])
		{
			primes[np++] = i;
			for(long long j = i * i; j < N; j += i << 1)
				not_prime[j] = 1;
		}
}

int factors(int n)
{
	int r = 0;
	
	for(int i = 0; i < np && primes[i] * primes[i] <= n; ++i)
		while(!(n % primes[i]))
		{
			r++;
			n /= primes[i];
		}

	return r + (n > 1);
}

int main()
{
	sieve();

	int n_cases, x, k;
	
	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d", &x, &k);
		printf("%d\n", factors(x) >= k);
	}

	return 0;
}

