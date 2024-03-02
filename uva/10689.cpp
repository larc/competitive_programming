// 10689 - Yet another Number Sequence

#include <cstdio>

int a, b, mod;

struct fmat
{
	int m[2][2];

	fmat()
	{
		m[0][0] = 0;
		m[1][0] = m[0][1] = m[1][1] = 1;
	}

	fmat operator * (const fmat & fm)
	{
		fmat r;
		r.m[0][0] = ((m[0][0] * fm.m[0][0]) % mod + (m[0][1] * fm.m[1][0]) % mod) % mod;
		r.m[0][1] = ((m[0][0] * fm.m[1][0]) % mod + (m[0][1] * fm.m[1][1]) % mod) % mod;
		r.m[1][0] = ((m[1][0] * fm.m[0][0]) % mod + (m[1][1] * fm.m[1][0]) % mod) % mod;
		r.m[1][1] = ((m[1][0] * fm.m[1][0]) % mod + (m[1][1] * fm.m[1][1]) % mod) % mod;

		return r;
	}

	fmat pow(const int n)
	{
		fmat r;
		if(n == 1) return r;

		r = r.pow(n >> 1);
		r = r * r;

		if(n & 1) r = r * (*this);
		return r;
	}

	int operator()(const int n)
	{
		if(n < 2) return n % mod;

		fmat r = pow(n);
		return (r.m[0][0] * (a % mod) + r.m[0][1] * (b % mod)) % mod;
	}
};

int main()
{
	fmat fib;
	int M[5] = {1, 10, 100, 1000, 10000};
	int n, m, n_cases;

	scanf("%u", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d %d %d", &a, &b, &n, &m);

		mod = M[m];

		if(!n) printf("%d\n", a);
		else printf("%u\n", fib(n));
	}

	return 0;
}

