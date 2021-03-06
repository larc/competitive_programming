#include <cstdio>

#define N 2000001

int phi[N];
int depth_phi[N];

void sieve_phi()
{
	for(int i = 0; i < N; ++i)
		phi[i] = i;

	for(int i = 2; i < N; ++i)
	{
		if(phi[i] == i)
		for(int n = i; n < N; n += i)
			phi[n] = (phi[n] / i) * (i - 1);
	}

	depth_phi[1] = 0;
	for(int i = 2; i < N; ++i)
		depth_phi[i] = 1 + depth_phi[phi[i]];
	
	for(int i = 2; i < N; ++i)
		depth_phi[i] += depth_phi[i - 1];
}

int main()
{
	sieve_phi();
	
	int c, m, n;
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d %d", &m, &n);
		printf("%d\n", depth_phi[n] - depth_phi[m - 1]);
	}
	return 0;
}

