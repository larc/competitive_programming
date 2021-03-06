// 516 - Prime Land

#include <cstdio>
#include <cmath>

#define N 32768

int primes[N];
int n_primes;

void sieve()
{
	bool not_prime[N] = { 0 };

	n_primes = 0;
	primes[n_primes++] = 2;

	for(int i = 3; i < N; i += 2)
		if(!not_prime[i])
		{
			primes[n_primes++] = i;
			for(int j = i * i; j < N; j += i << 1)
				not_prime[j] = 1;
		}
}

int main()
{
	sieve();

	char line[1024];
	int b, n, num, offset, o;
	int base[N << 1];

	while(fgets(line, sizeof(line), stdin) && line[0] != '0')
	{
		num = 1;
		offset = 0;
		while(sscanf(line + offset, "%d %d%n", &b, &n, &o) != EOF)
		{
			offset += o;
			num *= pow(b, n);
		}
		
		num--;

		b = 0;
		for(int i = 0; i < n_primes && primes[i] <= num; ++i)
		{
			n = 0;
			while(num % primes[i] == 0)
			{
				num /= primes[i];
				n++;
			}

			if(n)
			{
				base[b++] = n;
				base[b++] = primes[i];
			}
		}
		
		printf("%d", base[--b]);
		while(b--) printf(" %d", base[b]);
		putchar('\n');
	}

	return 0;
}

