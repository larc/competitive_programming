#include <cstdio>
#include <bitset>
#include <cmath>

#define N 1000000000//50001
#define S 1000001
#define P 5133 //previous counting

using namespace std;

size_t primes[P];
bitset<N> n_primes;
bitset<S> seg_primes;

void sieve()
{
	n_primes[1] = 1;

	size_t p = 0;
	for(size_t i = 2; i < N; ++i)
	{
		if(!n_primes[i])
		{
			p++;
		//	primes[p++] = i;
			for(size_t j = i * i; j < N; j += i)
				n_primes[j] = 1;
		}
	}
	printf("%ld\n", p);
}

bool is_prime(const size_t & n)
{
	if(n < N) return !n_primes[n];

	size_t sq = sqrt(n);

	for(size_t i = 0; i < P && primes[i] < sq; ++i)
		if(!(n % primes[i])) return false;

	return true;
}

int main()
{
	//sieve();
	size_t L, U;
	size_t min, max, dist;
	size_t c[2], d[2]; //closest and most distant primes
	size_t p; //previous prime
	printf("%ld %ld\n", sizeof(char), sizeof(bool));
	return 0;
	while(scanf("%ld %ld", &L, &U) != EOF)
	{
		seg_primes.reset();
		for(size_t i = 0; i < P && primes[i] * primes[i] <= U; ++i)
		{
			p = primes[i];
			for(size_t n = L % p ? L : L - p + L % p; n <= U; n += p)
			;

		}

		c[0] = c[1] = -1;
		d[0] = d[1] = -1;
		p = 0;
		for(size_t n = L; n <= U; ++n)
		{
			if(seg_primes[n - L])
			{
				if(p)
				{
					if(c[0] == -1)
					{
						c[0] = d[0] = p;
						c[1] = d[1] = n;
						min = max = n - p;
					}
					else
					{
						dist = n - p;
						if(min > dist)
						{
							min = dist;
							c[0] = p;
							c[1] = n;
						}
						if(max < dist)
						{
							max = dist;
							d[0] = p;
							d[1] = n;
						}
					}

				}
				p = n;
			}
		}
		if(c[0] != -1) printf("%ld,%ld are closest, %ld,%ld are most distant.\n", c[0], c[1], d[0], d[1]);
		else printf("There are no adjacent primes.\n");
	}

	return 0;
}

