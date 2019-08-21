#include <cstdio>

#define N 101

int main()
{
	int n, c;
	char bin[N];
	
	scanf("%s", bin);

	n = 1; c = 0;
	while(bin[n])
		if(bin[n++] == '1')
			c++;
	
	printf("%d\n", (n >> 1) + (c > 0 && n & 1));

	return 0;
}

