#include <cstdio>

int main()
{
	char c[128],  * i;
	int n;
	
	while(scanf("%s", c) != EOF)
	{
		i = c;
		n = 0;
		while(*i)
		{
			if(*i == '#')
			{
				if(n) printf("NO\n");
				else printf("YES\n");
				n = 0;
			}
			else
			{
				n <<= 1;
				n += *i - '0';
				n %= 131071;
			}
			i++;
		}
	}

	return 0;
}

