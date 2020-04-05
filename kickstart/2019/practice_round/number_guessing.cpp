#include <cstdio>

int main()
{
	char str[10];
	int t, n, a, b, p;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &a, &b);
		scanf("%d", &n);
		
		a++;
		while(n--)
		{
			p = (a + b) >> 1;
			printf("%d\n", p); fflush(stdout);

			scanf("%s", str);
			if(str[0] == 'C') break;
			if(str[0] == 'W') return 0;

			if(str[4] == 'S') a = p + 1;
			else b = p - 1;
		}
	}

	return 0;
}

