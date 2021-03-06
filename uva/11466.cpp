// 11466 - Largest Prime Divisor

#include <cstdio>
#include <cstring>

#define N 31622777 // sqrt 10^15

typedef long long int_t;

int_t * primes;
int_t n_primes;

void sieve()
{
	primes = new int_t[N];
	bool * not_prime = new bool[N];
	memset(not_prime, 0, sizeof(bool) * N);
	
	n_primes = 0;
	primes[n_primes++] = 2;

	for(int_t i = 3; i < N; ++i)
		if(!not_prime[i])
		{
			primes[n_primes++] = i;
			for(int_t j = i * i; j < N; j += i << 1)
				not_prime[i] = 1;
		}
	
	delete [] not_prime;
}

int main()
{
	sieve();
	int_t n, m, p;

	while(scanf("%lld", &n), n)
	{
		if(n < 0) n = -n;

		m = 0;
		for(int_t i = 0; i < n_primes && primes[i] * primes[i] <= n; ++i)
			if(n % primes[i] == 0)
			{
				p = primes[i];
				m++;

				while(n % p == 0) n /= p;
			}

		if(n > 1) { p = n; m++; }

		if(m > 1) printf("%lld\n", p);
		else printf("-1\n");
	}


	delete [] primes;
	return 0;
}

