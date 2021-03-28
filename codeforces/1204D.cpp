#include <cstdio>

#define N 100001

int main()
{
	char str[N];
	scanf("%s", str);

	int n = 0;
	while(str[++n]);

	int zeros = 0;
	while(n--)
		if(str[n] == '1')
			if(!zeros) str[n] = '0';
			else zeros--;
		else zeros++;

	printf("%s\n", str);

	return 0;
}

