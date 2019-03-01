// 11287 - Pseudoprime Numbers

#include <cstdio>
#include <cstring>

#define N 31624

bool not_prime[N];
int primes[N], np;

void sieve()
{
	memset(not_prime, 0, sizeof(N));

	not_prime[0] = not_prime[1] = 1;
	
	np = 0;
	for(int i = 2; i < N; i++)
	{
		if(!not_prime[i])
		{
			primes[np++] = i;
			for(int j = i * i; j < N; j += i)
				not_prime[j] = 1;
		}
	}
}

bool is_prime(const int & p)
{
	if(p < N) return !not_prime[p];

	for(int i = 0; i < np && primes[i] * primes[i] <= p; i++)
		if(!(p % primes[i]))
			return 0;
	
	return 1;
}

int mod_pow(const int & b, const int & n, const int & p)
{
	if(!n) return 1;

	long long r = mod_pow(b, n >> 1, p);
	
	r = (r * r) % p;

	return n & 1 ? (r * b) % p : r;
}

int main()
{
	sieve();	

	int p, a;
	while(scanf("%d %d", &p, &a) && p)
		printf("%s\n", !is_prime(p) && mod_pow(a, p, p) == a ? "yes" : "no");
	
	return 0;
}

