// 10235 - Simply Emirp

#include <cstdio>
#include <cstring>

#define N 1000000

bool not_prime[N];

void sieve()
{
	memset(not_prime, 0, sizeof(not_prime));

	not_prime[0] = not_prime[1] = 1;
	for(long long i = 2; i < N; i++)
		if(!not_prime[i])
			for(long long j = i * i; j < N; j += i)
				not_prime[j] = 1;
}

int reverse(int n)
{
	int r = 0;
	while(n)
	{
		r *= 10;
		r += n % 10;
		n /= 10;
	}

	return r;
}

int main()
{
	sieve();

	int n, r;
	while(scanf("%d", &n) != EOF)
		if(not_prime[n]) printf("%d is not prime.\n", n);
		else
		{
			r = reverse(n);
			printf("%d is %s.\n", n, n == r || not_prime[r] ? "prime" : "emirp");
		}

	return 0;
}

