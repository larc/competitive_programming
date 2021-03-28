// 10931 - Parity

#include <cstdio>
#include <algorithm>

int main()
{
	char num[32];
	unsigned int n, i, parity;

	while(scanf("%u", &n), n)
	{
		i = 0;
		parity = 0;

		while(n)
		{
			num[i++] = (n & 1) + '0';
			if(n & 1) parity++;
			n >>= 1;
		}

		num[i] = 0;
		std::reverse(num, num + i);
		printf("The parity of %s is %d (mod 2).\n", num, parity);
	}

	return 0;
}

