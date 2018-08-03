// 10338 - Mischievous Children

#include <cstdio>
#include <cstring>
#include <cmath>

#define N 21

unsigned int factors(unsigned int n, const unsigned int & p)
{
	unsigned int c = 0;
	while(n)
	{
		n /= p;
		c += n;
	}
	return c;
}

int main()
{
	unsigned int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	unsigned int n_primes = sizeof(primes) / sizeof(int);
	unsigned int n_cases;

	char word[N];
	unsigned int alpha[27];

	unsigned int prime_factors[n_primes];
	unsigned long int n;

	scanf("%u", &n_cases);
	for(int c = 1; c <= n_cases; c++)
	{
		memset(alpha, 0, sizeof(alpha));
		memset(prime_factors, 0, sizeof(prime_factors));

		scanf("%s", word);
		for(n = 0; word[n]; n++)
			alpha[word[n] - 'A']++;

		for(int i = 0; i < n_primes && primes[i] <= n; i++)
			prime_factors[i] = factors(n, primes[i]);
		
		for(int a = 0; a < 27; a++)
		for(int i = 0; i < n_primes && primes[i] <= alpha[a]; i++)
			prime_factors[i] -= factors(alpha[a], primes[i]);

		n = 1;
		for(int i = 0; i < n_primes; i++)
			n *= pow(primes[i], prime_factors[i]);
	
		printf("Data set %d: %lu\n", c, n);
	}

	return 0;
}

