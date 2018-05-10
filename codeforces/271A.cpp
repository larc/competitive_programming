#include <cstdio>
#include <cstring>

bool digits[10];
bool distinct(int n)
{
	memset(digits, 0, sizeof(digits));

	while(n)
	{
		if(digits[n % 10]) return 0;

		digits[n % 10] = 1;
		n /= 10;
	}

	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);

	while(!distinct(++n));

	printf("%d\n", n);

	return 0;
}

