#include <cstdio>

int main()
{
	int n, k, d;
	scanf("%d %d", &n, &k);

	while(k)
	{
		d = n % 10;
		if(k > d)
		{
			n /= 10;
			k -= d + 1;
		}
		else
		{
			n -= k;
			k = 0;
		}
	}

	printf("%d\n", n);

	return 0;
}

