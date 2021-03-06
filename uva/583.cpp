// 583 - Prime Factors

#include <cstdio>
#include <cstring>

#define N 46342		// sqrt(2^31 - 1)

int primes[N], n_primes;

void calc_primes()
{
	bool not_prime[N];
	memset(not_prime, 0, sizeof(not_prime));
	
	n_primes = 0;
	primes[n_primes++] = 2;
	for(int i = 3; i < N; i += 2)
		if(!not_prime[i])
		{
			primes[n_primes++] = i;
			for(int j = i * i; j < N; j += i)
				not_prime[j] = 1;
		}
}

int main()
{
	calc_primes();

	int n;
	bool flag;

	while(scanf("%d", &n), n)
	{
		printf("%d =", n);

		flag = 0;
		if(n < 0)
		{
			printf(" -1");
			flag = 1;

			n = -n;
		}

		for(int i = 0; i < n_primes && primes[i] <= n; ++i)
		{
			const int & p = primes[i];
			while(!(n % p))
			{
				if(flag) printf(" x %d", p);
				else
				{
					printf(" %d", p);
					flag = 1;
				}

				n /= p;
			}
		}

		if(n > 1)
		{
			if(flag) printf(" x %d", n);
			else printf(" %d", n);
		}
		
		putchar('\n');
	}

	return 0;
}

