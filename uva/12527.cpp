// 12527 - Different Digits

#include <cstdio>
#include <cstring>

bool d[10];

bool repeat_digits(int n)
{
	memset(d, 0, sizeof(d));

	int r;
	while(n)
	{
		r = n % 10;
		n /= 10;

		if(d[r]) return 0;
		d[r] = 1;
	}

	return 1;
}

int main()
{
	int a, b, c;
	while(scanf("%d %d", &a, &b) != EOF)
	{
		c = 0;
		while(a <= b)
			c += repeat_digits(a++);
		printf("%d\n", c);
	}

	return 0;
}

