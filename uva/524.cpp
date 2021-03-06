// 524 - Prime Ring Problem

#include <cstdio>
#include <cstring>

#define N 16
#define M 32

int ring[N];
bool not_prime[M];
bool selected[N];

void init_prime()
{
	memset(not_prime, 0, sizeof(not_prime));

	for(int i = 2; i < M; ++i)
		if(!not_prime[i])
			for(int j = i * i; j < M; j += i)
				not_prime[j] = 1;
}

void prime_ring(const int & n, const int & p)
{
	if(n == p && !not_prime[ring[p - 1] + ring[0]])
	{
		printf("%d", ring[0]);
		for(int i = 1; i < p; ++i)
			printf(" %d", ring[i]);
		putchar('\n');

		return;
	}
	
	for(int i = 2 + !(p & 1); i <= n; i += 2)
		if(!selected[i] && !not_prime[i + ring[p - 1]])
		{
			selected[i] = 1;
			ring[p] = i;
			prime_ring(n, p + 1);
			selected[i] = 0;
		}
}

int main()
{
	init_prime();
	
	int n, n_cases = 1;
	
	ring[0] = 1;
	scanf("%d", &n);

	while(1)
	{
		printf("Case %d:\n", n_cases++);

		memset(selected, 0, sizeof(selected));
		prime_ring(n, 1);

		if(scanf("%d", &n) == EOF) break;
		putchar('\n');
	}

	return 0;
}

