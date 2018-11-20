// 2014 - Looking for the Risk Factor

#include <cstdio>
#include <algorithm>

#define N 100001

int primes[N], np;

void sieve()
{
	bool not_prime[N] = {};
	
	np = 0;
	primes[np++] = 2;

	for(long long i = 3; i < N; i += 2)
	{
		if(!not_prime[i])
		{
			primes[np++] = i;
			for(long long j = i * i; j < N; j += i << 1)
				not_prime[j] = 1;
		}
	}
}

int count(const int & n, const int & p, const int & i)
{
	int c = n / p;
	int r = 0;

	for(int k = i; primes[k] < p && primes[k] <= c; k++)
		r += count(c, primes[k], i);
	
	return c - r;
}

int main()
{
	sieve();

	int q, n, k, c, i;
	
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d", &n, &k);
		
		c = 0;
		i = std::upper_bound(primes, primes + np, k) - primes;
		for(int j = i; j < np && primes[j] <= n; j++)
			c += count(n, primes[j], i);

		printf("%d\n", n - c - 1);
	}

	return 0;
}

