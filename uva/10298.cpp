// 10298 - Power Strings

#include <cstdio>

#define N 1000001

int main()
{
	int i, j;
	int b[N];

	char str[N];
	while(scanf("%s", str), str[0] != '.')
	{
		// KMP algorithm
		i = 0; j = -1; b[0] = -1;
		while(str[i])
		{
			while(j >= 0 && str[i] != str[j]) j = b[j];
			i++; j++;
			b[i] = j;
		}
		
		if(i % (i - j)) printf("1\n");
		else printf("%d\n", i / (i - j));
	}

	return 0;
}

