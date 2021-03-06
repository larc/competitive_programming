// 2914 - Looking for the Risk Factor

#include <cstdio>
#include <vector>
#include <algorithm>

#define N 100001

int primes[N], np;

void sieve()
{
	bool not_prime[N] = {};
	
	np = 0;
	primes[np++] = 2;

	for(long long i = 3; i < N; i += 2)
	{
		if(!not_prime[i])
		{
			primes[np++] = i;
			for(long long j = i * i; j < N; j += i << 1)
				not_prime[j] = 1;
		}
	}
}

int ft[N];	// Fenwick Tree (BIT)

void adjust(int i, const int & v)
{
	while(i < N)
	{
		ft[i] += v;
		i += i & -i;
	}
}

int rsq(int i)
{
	int sum = 0;

	while(i)
	{
		sum += ft[i];
		i -= i & - i;
	}

	return sum;
}

int main()
{
	sieve();
	bool removed[N] = {};

	int q, k, ini;
	int qn[N], qk[N];
	
	scanf("%d", &q);
	std::vector<int> qi(q);

	for(int i = 0; i < q; ++i)
	{
		scanf("%d %d", qn + i, qk + i);
		qi[i] = i;
	}
		
	std::sort(qi.begin(), qi.end(), [&qk](const int & i, const int & j) { return qk[i] > qk[j]; });

	ft[0] = ft[1] = 0;
	for(int i = 2; i < N; ++i)
		adjust(i, 1);
	
	int stop = np;
	for(const int & i: qi)
	{
		k = qk[i];
		ini = k = std::upper_bound(primes, primes + np, k) - primes;
		while(k < stop)
		{
			for(int j = primes[k]; j < N; j += primes[k])
				if(!removed[j])
				{
					removed[j] = 1;
					adjust(j, -1);
				}
			k++;
		}
		
		stop = ini;
		qn[i] = rsq(qn[i]);
	}

	for(int i = 0; i < q; ++i)
		printf("%d\n", qn[i]);

	return 0;
}

