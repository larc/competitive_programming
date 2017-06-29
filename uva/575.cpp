#include <cstdio>

int decimal(char * c, int & p)
{
	if(*c == '\0') return 0;
	int d = decimal(c + 1, p);
	p <<= 1;
	return d + (*c - '0') * (p - 1);
}

int main()
{
	char skew[32];
	int p;
	while(scanf("%s", skew) && *skew != '0')
		printf("%d\n", decimal(skew, p = 1));
	return 0;
}

