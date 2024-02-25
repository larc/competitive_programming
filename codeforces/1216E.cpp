#include <cstdio>

#define N 10

typedef unsigned long long llu;

llu p10[N];
llu B[N], S[N + 1];

/*
inline llu S(const llu n)
{
	return n * p10[n - 1] - (p10[n] - 1) / 9;
}
*/

inline llu T(const llu n, const llu r)
{
	return r * S[n] + n * r * (r + 1) / 2;
}

int main()
{
	p10[0] = 1;
	for(int i = 1; i < N; ++i)
		p10[i] = p10[i - 1] * 10;

	S[0] = S[1] = 0;
	for(int i = 2; i <= N; ++i)
		S[i] = S[i - 1] + 9 * (i - 1) * p10[i - 2];

	B[0] = 0;
	for(int i = 1; i < N; ++i)
		B[i] = B[i - 1] + T(i, 9 * p10[i - 1]);

	llu k, i, j, r, q, n;

	scanf("%llu", &q);
	while(q--)
	{
		scanf("%llu", &k);

		n = 0;
		while(k > B[++n]);

		k -= B[n - 1];

		i = 1; j = 9 * p10[n - 1];
		while(i <= j)
		{
			r = (i + j) >> 1;

			if(i == j) break;

			if(k > T(n, r)) i = r + 1;
			else j = r;
		}

		k -= T(n, r - 1);

		n = 0;
		while(k > S[n + 1]) n++;

		k -= S[n];

		i = (k - 1) % n;
		k = (k - 1) / n + p10[n - 1];

		i = n - i - 1;
		k /= p10[i];

		printf("%llu\n", k % 10);
	}

	return 0;
}

