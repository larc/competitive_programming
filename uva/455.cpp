// 455 - Periodic Strings

#include <cstdio>

#define N 128

int main()
{
	int i, j, n;
	int b[N];
	char str[N];

	scanf("%d", &n);
	fgets(str, sizeof(str), stdin);
	while(n--)
	{
		fgets(str, sizeof(str), stdin);
		fgets(str, sizeof(str), stdin);

		// KMP algorithm
		i = 0; j = -1; b[0] = -1;
		while(str[i] != '\n')
		{
			while(j >= 0 && str[i] != str[j])
				j = b[j];

			b[++i] = ++j;
		}

		printf("%d\n", i % (i - j) ? i : i - j);
		if(n) putchar('\n');
	}

	return 0;
}

