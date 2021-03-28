// 11220 - Decoding the message

#include <cstdio>

int main()
{
	int n_cases, n, i, j;
	char line[1024];
	char word[32];

	scanf("%d", &n_cases);
	fgets(line, sizeof(line), stdin);
	fgets(line, sizeof(line), stdin);
	for(int c = 1; c <= n_cases; ++c)
	{
		printf("Case #%d:\n", c);

		while(fgets(line, sizeof(line), stdin) && line[0] != '\n')
		{
			n = i = 0;
			while(line[i])
			{
				j = 0;
				while(line[i + j] != ' ' && line[i + j] != '\n') j++;

				if(n < j) word[n++] = line[i + n];
				i += j + 1;
			}

			word[n] = 0;
			printf("%s\n", word);
		}

		if(c < n_cases) putchar('\n');
	}

	return 0;
}

