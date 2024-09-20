#include <cstdio>
#include <vector>

#define N 32000


bool not_prime[N] = {};
int primes[N];
int n_primes;

void sieve()
{
	n_primes = 0;

	not_prime[0] = 1;
	not_prime[1] = 1;
	for(int i = 2; i < N; ++i)
	{
		if(not_prime[i]) continue;

		primes[n_primes++] = i;
		for(int j = i * i; j < N; j += i)
			not_prime[j] = 1;
	}
}

int main()
{
	sieve();

	int n, x, a, b;
	std::vector<int> sums(N);

	scanf("%d", &n);
	while(n--)
	{
		sums.clear();

		scanf("%d", &x);
		for(int i = 0; i < n_primes; ++i)
		{
			a = primes[i];
			if(a + a > x) break;

			b = x - a;
			if(not_prime[b]) continue;

			sums.push_back(a);
		}

		printf("%d has %lu representation(s)\n", x, size(sums));
		for(const int e: sums)
			printf("%d+%d\n", e, x - e);
		printf("\n");
	}

	return 0;
}

