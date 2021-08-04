#include <cstdio>

#define N 2000001

int main()
{
	int i, j;
	int * b = new int[N];
	char * str = new char[N];

	while(scanf("%s", str) && str[0] != '.')
	{
		// KMP algorithm
		i = 0; j = -1; b[0] = -1;
		while(str[i])
		{
			while(j >= 0 && str[i] != str[j])
				j = b[j];

			b[++i] = ++j;
		}

		printf("%d\n", i % (i - j) ? 1 : i / (i - j));
	}

	delete [] b;
	delete [] str;

	return 0;
}

