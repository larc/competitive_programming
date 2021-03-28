// 10018 - Reverse and Add

#include <cstdio>

unsigned int reverse(unsigned int n)
{
	unsigned int p = 0;
	while(n)
	{
		p = p * 10 + n % 10;
		n /= 10;
	}

	return p;
}

int main()
{
	unsigned int n_cases, n, p, c;

	scanf("%u", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);

		c = 0;
		p = reverse(n);
		do
		{
			c++;
			n += p;
			p = reverse(n);
		}
		while(n != p);

		printf("%u %u\n", c, n);
	}

	return 0;
}

