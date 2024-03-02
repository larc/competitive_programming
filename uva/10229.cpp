// 10229 - Modular Fibonacci

#include <cstdio>

unsigned int mod;
struct fmat
{
	unsigned int m[2][2];

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

	fmat pow(const unsigned int n)
	{
		fmat r;
		if(n == 1) return r;

		r = r.pow(n >> 1);
		r = r * r;

		if(n & 1) r = r * (*this);
		return r;
	}

	unsigned int operator()(const unsigned int n)
	{
		if(n < 2) return n % mod;

		fmat r = pow(n);
		return r.m[0][1];
	}
};

int main()
{
	fmat fib;
	unsigned int n, m;
	while(scanf("%u %u", &n, &m) != EOF)
	{
		mod = 1 << m;
		if(n < 2) printf("%u\n", n % mod);
		else printf("%u\n", fib(n));
	}

	return 0;
}

