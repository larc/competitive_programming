// 10179 - Irreducable Basic Fractions

#include <cstdio>

#define N 31623		// sqrt(10^9)

int main()
{
	bool not_prime[N] = { 0 };
	int primes[N];
	int n_primes = 0;

	primes[n_primes++] = 2;
	for(int i = 3; i < N; i++)
		if(!not_prime[i])
		{
			primes[n_primes++] = i;
			for(int j = i * i; j < N; j += (i << 1))
				not_prime[j] = 1;
		}
	
	int n, phi;

	while(scanf("%d", &n), n)
	{
		phi = n;	// Euler Phi
		
		for(int i = 0; i < n_primes && primes[i] <= n; i++)
			if(n % primes[i] == 0)
			{
				phi -= phi / primes[i];
				while(n % primes[i] == 0) n /= primes[i];
			}
		
		if(n > 1) phi -= phi / n;
		printf("%d\n", phi);
	}

	return 0;
}

