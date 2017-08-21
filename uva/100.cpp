#include <cstdio>
#include <cstring>

#define N 1000000

int C[N];

int cycle(int n)
{
	if(n == 1) return 1;
	if(n >= N)
	{
		if(n & 1) return 1 + cycle(3 * n + 1);
		return 1 + cycle(n >> 1);
	}

	if(!C[n])
	{
		if(n & 1) C[n] = 1 + cycle(3 * n + 1);
		else C[n] = 1 + cycle(n >> 1);
	}

	return C[n];
}

int max_cycle(int i, int j)
{
	int c, m = 0;

	while(i <= j)
	{
		c = cycle(i++);
		if(c > m) m = c;
	}

	return m;
}

int main()
{
	int a, b, c;
	memset(C, 0, sizeof(C));
	
	while(scanf("%d %d", &a, &b) != EOF)
	{
		if(a < b) c = max_cycle(a, b);
		else c = max_cycle(b, a);
		printf("%d %d %d\n", a, b, c);
	}

	return 0;
}
