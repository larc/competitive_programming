// 10551 - Basic Remains

#include <cstdio>

int to_base(int n, const int & b_in, const int & b_out)
{
	int r = 0;
	int p = 1;
	
	while(n)
	{
		r += (n % b_out) * p;
		p *= b_in;
		n /= b_out;
	}

	return r;
}

int main()
{
	int b, m;
	char p[1001];
	long long r;

	while(scanf("%d", &b) && b)
	{
		scanf("%s %d", p, &m);
		m = to_base(m, b, 10);
		
		r = 0;
		for(int i = 0; p[i]; i++)
		{
			r = (r * b) % m;
			r = (r + p[i] - '0') % m;
		}
		
		printf("%d\n", to_base(r, 10, b));
	}

	return 0;
}

