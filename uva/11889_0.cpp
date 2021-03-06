// 11889 - Benefit

#include <cstdio>

int gcd(const int & a, const int & b)
{
	if(!b) return a;
	return gcd(b, a % b);
}

// gcd and lcm solution
int main()
{
	int a, b, c, n;

	scanf("%d", &n);
	while(n-- && scanf("%d %d", &a, &c))
	{
		if(c % a != 0) printf("NO SOLUTION\n");
		else
		{
			b = c;
			for(int i = 1; i * i <= c; ++i)
				if(c % i == 0)
				{
					if(i < b && (a / gcd(a, i)) * i == c)
						b = i;

					if(c / i < b && a == gcd(a, c / i) * i)
						b = c / i;
				}

			printf("%d\n", b);
		}
	}

	return 0;
}

