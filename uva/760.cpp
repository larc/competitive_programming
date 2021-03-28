// 760 - DNA Sequencing

#include <cstdio>
#include <string>
#include <algorithm>

#define N 301

int main()
{
	char a[N], b[N], c[N];
	std::string str[N];
	int n, max_n, s;

	scanf("%s %s", a, b);
	while(1)
	{
		max_n = 0;
		s = 0;
		for(int i = 0; a[i] != '\0'; ++i)
		for(int j = 0; b[j] != '\0'; ++j)
			if(a[i] == b[j])
			{
				n = 0;
				while(a[i + n] != '\0' && a[i + n] == b[j + n])
				{
					c[n] = a[i + n];
					n++;
				}
				c[n] = '\0';

				if(max_n < n)
				{
					s = 0;
					max_n = n;
				}

				if(n == max_n) str[s++] = c;
			}

		if(!s) printf("No common sequence.\n");
		else
		{
			std::sort(str, str + s);
			printf("%s\n", str[0].c_str());
			for(int i = 1; i < s; ++i)
				if(str[i] != str[i - 1])
					printf("%s\n", str[i].c_str());
		}

		if(scanf("%s %s", a, b) != EOF) putchar('\n');
		else break;
	}

	return 0;
}

