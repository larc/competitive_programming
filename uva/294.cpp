#include <cstdio>
#include <cstring>

#define L 31622
#define P 3401

int primes[P];

int find_primes()
{
	int n_primes = 0;

	bool is_prime[L];
	memset(is_prime, 0, sizeof(is_prime));
	
	primes[n_primes++] = 2;
	for(int i = 3; i < L; i += 2)
	{
		if(!is_prime[i])
		{
			primes[n_primes++] = i;
			for(int j = i * i; j < L; j += i << 1)
				is_prime[j] = 1;
		}
	}

	return n_primes;
}

int divisors(int n)
{
	int d = 1, c, p;
	for(int i = 0; i < P && primes[i] * primes[i] <= n; ++i)
	{
		p = primes[i];
		c = 0;
		while(!(n % p))
		{
			c++;
			n /= p;
		}

		d *= c + 1;
	}
	
	if(n > 1) d <<= 1;
	return d;
}

int main()
{
	int n, l, u, d, max_d, p;
	int n_primes = find_primes();

	//printf("%d\n", divisors(1000));

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &l, &u);

		max_d = 0;
		for(int i = l; i <= u; ++i)
		{
			d = divisors(i);
			if(d > max_d)
			{
				max_d = d;
				p = i;
			}
		}

		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, p, max_d);
	}
	return 0;
}

