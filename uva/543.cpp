#include <cstdio>
#include <cstring>
#include <cmath>

#define N 78498
#define S 1000000

int primes[N];
bool not_prime[S];

void sieve()
{
	memset(not_prime, 0, sizeof(not_prime));
	not_prime[0] = 1;
	not_prime[1] = 1;
	
	int p = 0;
	primes[p++] = 2;

	for(size_t i = 3; i < S; i += 2)
	{
		if(!not_prime[i])
		{
			primes[p++] = i;
			for(size_t j = i * i; j < S; j += i << 1)
				not_prime[j] = 1;
		}
	}
}

int main()
{
	sieve();

	int n, a, b, sq;
	bool prime;
	while(scanf("%d", &n) && n)
	{
		for(a = 0; primes[a] < n; ++a)
		{	
			b = n - primes[a];
			if(b % 2 && !not_prime[b]) break;
		}
		if(a == N) printf("Goldbach's conjecture is wrong.\n");
		else printf("%d = %d + %d\n", n, primes[a], b);
	}

	return 0;
}

