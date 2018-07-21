// 10699 - Count the factors

#include <cstdio>

#define N 1000

int main()
{
	bool not_prime[N] = { 0 };
	int primes[N];
	int n_primes = 0;

	primes[n_primes++] = 2;
	for(int i = 3; i < N; i += 2)
		if(!not_prime[i])
		{
			primes[n_primes++] = i;
			for(int j = i * i; j < N; j += i)
				not_prime[j] = 1;
		}

	
	int n, m, p;
	while(scanf("%d", &n), n)
	{
		p = 0; m = n;
		for(int i = 0; i < n_primes && primes[i] <= n; i++)
			if(n % primes[i] == 0)
			{
				p++;
				while(n % primes[i] == 0) n /= primes[i];
			}

		if(n > 1) p++;
		printf("%d : %d\n", m, p);
	}

	return 0;
}

