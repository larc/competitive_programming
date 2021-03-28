#include <cstdio>
#include <cstring>

bool digits[10];

bool common(int n)
{
	while(n)
	{
		if(digits[n % 10]) return 1;
		n /= 10;
	}
	return 0;
}

int main()
{
	memset(digits, 0, sizeof(digits));

	int x, d, count;
	scanf("%d", &x);

	d = x;
	while(d)
	{
		digits[d % 10] = 1;
		d /= 10;
	}

	count = 0;
	for(d = 1; d * d < x; ++d)
		if(!(x % d))
		{
			if(common(d)) count++;
			if(common(x / d)) count++;
		}

	if(d * d == x && common(d)) count++;

	printf("%d\n", count);

	return 0;
}

