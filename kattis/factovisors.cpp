#include <cstdio>
#include <vector>

#define N 46340

std::vector<int> primes;

void sieve()
{
	bool not_prime[N] = { 0 };
	primes.reserve(N);

	primes.push_back(2);
	for(int i = 3; i < N ; ++i)
		if(!not_prime[i])
		{
			primes.push_back(i);
			for(int j = i * i; j < N; j += (i << 1))
				not_prime[j] = 1;
		}
}

int factovisors(int n, const int & p)
{
	int count = 0;
	while(n)
	{
		n /= p;
		count += n;
	}
	return count;
}

int prime_pow(int & n, const int & p)
{
	int count = 0;
	while(n % p == 0)
	{
		++count;
		n /= p;
	}
	return count;
}

bool divide(int m, int n)
{
	for(const int & p: primes)
	{
		if(p * p > m) break;
		if(prime_pow(m, p) > factovisors(n, p))
			return false;
	}

	return m > 1 ? n >= m : true;
}

int main()
{
	sieve();

	int n, m;

	while(scanf("%d %d", &n, &m) != EOF)
		if(m && divide(m, n))
			printf("%d divides %d!\n", m, n);
		else
			printf("%d does not divide %d!\n", m, n);

	return 0;
}

