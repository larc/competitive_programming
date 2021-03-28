#include <cstdio>

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);

	if(t == 10)
	{
		if(n != 1)
		{
			putchar('1');
			while(--n) putchar('0');
		}
		else printf("-1");
	}
	else
	{
		char c = t + '0';
		while(n--) putchar(c);
	}
	putchar('\n');

	return 0;
}

