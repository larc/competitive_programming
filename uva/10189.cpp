#include <cstdio>
#include <cstring>

char field[102][102];

int main()
{
	int m, n, f;
	char c;
	f = 0;
	while(scanf("%d %d", &m, &n) && m && n)
	{
		memset(field, 0, sizeof(field));

		for(int i = 1; i <= m; i++)
			scanf("%s", field[i] + 1);

		for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
		if(field[i][j] != '*')
		{
			c = 0;
			c += field[i - 1][j - 1] == '*';
			c += field[i - 1][j] == '*';
			c += field[i - 1][j + 1] == '*';
			c += field[i][j - 1] == '*';
			c += field[i][j + 1] == '*';
			c += field[i + 1][j - 1] == '*';
			c += field[i + 1][j] == '*';
			c += field[i + 1][j + 1] == '*';
			field[i][j] = c + '0';
		}

		if(f++) printf("\n");
		printf("Field #%d:\n", f);
		for(int i = 1; i <= m; i++)
		{
			field[i][n + 1] = '\0';
			printf("%s\n", field[i] + 1);
		}
	}
}

