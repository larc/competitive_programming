// 10394 - Twin Primes

#include <cstdio>
#include <cstring>

#define N 100001
#define M 20000001

int main()
{
	int p[N], s = 1;
	bool * not_prime = new bool[M];

	memset(not_prime, 0, sizeof(not_prime));
	for(int i = 3; i * i < M; i += 2)
		if(!not_prime[i])
			for(int j = i * i; j < M; j += i)
				not_prime[j] = 1;

	p[s++] = 3; p[s++] = 5;
	for(int i = 11; s < N; i += 6)
		if(!not_prime[i] && !not_prime[i + 2])
			p[s++] = i;

	while(scanf("%d", &s) != EOF)
		printf("(%d, %d)\n", p[s], p[s] + 2);

	delete [] not_prime;
	return 0;
}

