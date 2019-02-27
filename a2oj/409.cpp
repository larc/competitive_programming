// 409. The ThunderBolt 

#include <cstdio>

#define N 10001

bool not_prime[N] = {};

bool prime(int n)
{
	if(not_prime[n]) return 0;

	int p = 0;
	while(n)
	{
		p += n % 10;
		n /= 10;
	}
	
	return !not_prime[p];
}

int main()
{
	int count[N] = {};
	
	not_prime[0] = not_prime[1] = 1;
	for(int i = 2; i < N; i++)
	{
		count[i] = count[i - 1] + prime(i);
		if(!not_prime[i])
		{
			for(int j = i * i; j < N; j += i)
				not_prime[j] = 1;
		}
	}
	
	int n, a, b;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", count[b] - count[a - 1]);
	}

	return 0;
}

