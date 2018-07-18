// 10892 - LCM Cardinality

#include <cstdio>

#define N 120000

int gcd(const int & a, const int & b)
{
	if(!b) return a;
	return gcd(b, a % b);
}

int main()
{
	int n, div[N], m, d;
	
	div[0] = 1;
	while(scanf("%d", &n), n)
	{
		m = 1;
		if(n > 1) div[m++] = n;
		for(d = 2; d * d < n; d++)
			if(!(n % d))
			{
				div[m++] = d;
				div[m++] = n / d;
			}

		if(d * d == n) div[m++] = d;

		d = m;
		for(int i = 2; i < m; i++)
		for(int j = i + 1; j < m; j++)
			if((div[i] / gcd(div[i], div[j])) * div[j] == n)
				d++;

		printf("%d %d\n", n, d);
	}

	return 0;
}

