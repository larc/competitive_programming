// 1574 - Robot Instructions

#include <cstdio>


int main()
{
	char line[16], str[8];
	int c, n, i, j, p;
	int I[101];

	scanf("%d", &c);
	while(c--)
	{
		scanf("%d\n", &n);
		for(i = 1; i <= n; ++i)
		{
			fgets(line, sizeof(line), stdin);
			if(line[0] == 'L') I[i] = -1;
			else if(line[0] == 'R') I[i] = 1;
			else
			{
				sscanf(line, "%s %s %d", str, str + 4, &j);
				I[i] = I[j];
			}
		}

		p = 0;
		for(i = 1; i <= n; ++i)
			p += I[i];

		printf("%d\n", p);
	}

	return 0;
}

