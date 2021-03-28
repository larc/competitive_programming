#include <cstdio>

int P[11];
int A[10];
long long S[10];

void init()
{
	P[0] = 1;
	A[0] = 0;
	S[0] = 45;
	for(int i = 1; i < 10; ++i)
	{
		P[i] = P[i - 1] * 10;
		A[i] = A[i - 1] + i;
		S[i] = S[0] * i;
		S[0] *= 10;
	}

	P[10] = P[9] * 10;
}

long long sum(int n, const int & d)
{
	if(!d) return A[n];

	int i = n / P[d];
	int j = n % P[d];
	return sum(j, d - 1) + (S[d] + j + 1) * i + A[i - 1] * P[d];
}

long long sum(const int & n)
{
	int d = 0;
	while(n >= P[++d]);
	return sum(n, d - 1);
}

int digits(int n)
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

	int a, b;
	while(scanf("%d %d", &a, &b), a != -1 && b != -1)
		printf("%lld\n", sum(b) - sum(a) + digits(a));

	return 0;
}

