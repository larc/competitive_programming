#include <cstdio>
#include <cstring>
#include <vector>

#define N 31624

bool not_prime[N];
std::vector<int> primes;

void sieve()
{
	memset(not_prime, 0, sizeof(N));
	primes.reserve(N);

	not_prime[0] = not_prime[1] = true;

	primes.push_back(2);
	for(int i = 3; i < N; ++i)
		if(!not_prime[i])
		{
			primes.push_back(i);
			for(int j = i * i; j < N; j += (i << 1))
				not_prime[j] = true;
		}
}

bool is_prime(const int n)
{
	if(n < N) return !not_prime[n];

	for(const int p: primes)
	{
		if(p * p > n) break;
		if(!(n % p))
			return false;
	}

	return true;
}

int mod_pow(const int b, const int n, const int p)
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

