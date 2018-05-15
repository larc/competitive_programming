#include <cstdio>

typedef long long lld_t;

int A[10];
lld_t P[17];
lld_t S[16];

void init()
{
	P[0] = 1;
	A[0] = 0;
	S[0] = 45;
	for(int i = 1; i < 16; i++)
	{
		P[i] = P[i - 1] * 10;
		A[i] = A[i - 1] + i;
		S[i] = S[0] * i;
		S[0] *= 10;
	}
	
	P[16] = P[15] * 10;
}

lld_t sum(const lld_t & n, const int & d)
{
	if(!d) return A[n];

	lld_t i = n / P[d];
	lld_t j = n % P[d];
	return sum(j, d - 1) + (S[d] + j + 1) * i + A[i - 1] * P[d];
}

lld_t sum(const lld_t & n)
{
	int d = 0;
	while(n >= P[++d]);
	return sum(n, d - 1);
}

int digits(lld_t n)
{
	int s = 0;
	while(n)
	{
		s += n % 10;
		n /= 10;
	}

	return s;
}

int main()
{
	init();

	int c;
	lld_t a, b;

	scanf("%d", &c);
	while(c--)
	{	
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", sum(b) - sum(a) + digits(a));
	}

	return 0;
}

