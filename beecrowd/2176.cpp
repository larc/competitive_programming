// 2176 - Parity

#include<cstdio>


int main()
{
	char str[102];

	scanf("%s", str);

	char * c = str;
	int n = 0;

	while(*c)
	{
		n += (*c) - '0';
		++c;
	}

	*c = (n & 1) + '0';
	++c = 0;

	printf("%s\n", str);

	return 0;
}

