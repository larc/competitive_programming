// 10139 - Factovisors

#include <cstdio>

#define N 46340

int primes[N], n_primes = 0;

void sieve()
{
	bool not_prime[N] = { 0 };

	primes[n_primes++] = 2;
	for(int i = 3; i < N ; i++)
		if(!not_prime[i])
		{
			primes[n_primes++] = i;
			for(int j = i * i; j < N; j += (i << 1))
				not_prime[j] = 1;
		}
}

int factovisors(int n, const int & p)
{
	int count = 0;
	while(n)
	{
		count += n / p;
		n /= p;
	}
	return count;
}

int prime_pow(int & n, const int & p)
{
	int count = 0;

	while(n % p == 0)
	{
		count++;
		n /= p;
	}

	return count;
}

bool divide(int m, int n)
{
	for(int i = 0; i < n_primes && primes[i] <= m; i++)
	{
		if(prime_pow(m, primes[i]) > factovisors(n, primes[i]))
			return 0;
	}

	if(m > 1) return n >= m;
	return 1;
}

int main()
{
	sieve();

	int n, m;

	while(scanf("%d %d", &n, &m) != EOF)
		if(n >= m || divide(m, n)) printf("%d divides %d!\n", m, n);
		else printf("%d does not divide %d!\n", m, n);

	return 0;
}

