// 11889 - Benefit

#include <cstdio>
#include <cstring>

#define N 10000

int primes[N];
int n_primes;

void sieve()
{
	bool not_prime[N] = { 0 };

	n_primes = 0;
	primes[n_primes++] = 2;
	
	for(int i = 3; i < N; i += 2)
		if(!not_prime[i])
		{
			primes[n_primes++] = i;
			for(int j = i * i; j < N; j += i << 1)
				not_prime[j] = 1;
		}
}

int pow(const int & b, const int & n)
{
	if(!n) return 1;

	int r = pow(b, n >> 1);
	return n & 1 ? b * r * r : r * r;
}

// prime factors solution
int main()
{
	sieve();

	int a, b, c, n, fa, fc;

	scanf("%d", &n);
	while(n-- && scanf("%d %d", &a, &c))
	{
		if(c % a != 0) printf("NO SOLUTION\n");
		else
		{
			b = 1;
			for(int i = 0; primes[i] * primes[i] <= c; i++)
			{
				fa = fc = 0;
				const int & p = primes[i];
				while(a % p == 0) { fa++; a /= p; }
				while(c % p == 0) { fc++; c /= p; }

				if(fc > fa) b *= pow(p, fc);
			}
			
			if(c > 1 && a == 1) b *= c;
			printf("%d\n", b);
		}
	}

	return 0;
}

