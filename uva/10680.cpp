// 10680 - LCM

#include <cstdio>
#include <cstring>

#define N 1000000

unsigned primes[N];
unsigned n_primes = 0;

void sieve()
{
	bool not_prime[N] = { 0 };

	primes[n_primes++] = 2;

	for(long long i = 3; i < N; i += 2)
		if(!not_prime[i])
		{
			primes[n_primes++] = i;
			for(long long j = i * i; j < N; j += i << 1)
				not_prime[j] = 1;
		}
}

unsigned pow(const unsigned & b, const unsigned & n)
{
	if(!n) return 1;

	unsigned r = pow(b, n >> 1);
	r = (r * r) % 10;

	return n & 1 ? (r * b) % 10 : r;
}

int main()
{
	sieve();

	unsigned pfactors[n_primes];

	unsigned n, m;
	while(scanf("%u", &n), n)
	{
		memset(pfactors, 0, sizeof(pfactors));
		for(unsigned i = 0; i < n_primes && primes[i] <= n; ++i)
		{
			m = n;
			while(m /= primes[i])
				pfactors[i]++;
		}

		pfactors[0] -= pfactors[2];
		pfactors[2] -= pfactors[2];

		m = 1;
		for(unsigned i = 0; i < n_primes && primes[i] <= n; ++i)
		{
			m *= pow(primes[i], pfactors[i]);
			m %= 10;
		}

		printf("%u\n", m);
	}

	return 0;
}

