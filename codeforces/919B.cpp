#include <cstdio>
#include <cstring>

bool is_perfect(int n)
{
	int s = 0;
	while(n)
	{
		s += n % 10;
		n /= 10;
	}

	return s == 10;
}

int main()
{
	int k;
	scanf("%d", &k);

	int n = 19;
	while(k)
	{
		if(is_perfect(n)) k--;
		n++;
	}

	printf("%d\n", n - 1);

	return 0;
}

