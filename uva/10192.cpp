// 10192 - Vacation

#include <cstdio>
#include <cstring>

#define N 102

int main()
{
	char A[N], B[N];
	int table[N][N], n_cases, n, m;

	n_cases = 1;
	while(fgets(A, N, stdin), A[0] != '#')
	{
		fgets(B, N, stdin);

		memset(table, 0, sizeof(table));

		n = strlen(A) - 1;
		m = strlen(B) - 1;
		for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			table[i + 1][j + 1] = table[i][j] + (A[i] == B[j]);
			if(table[i + 1][j + 1] < table[i][j + 1])
				table[i + 1][j + 1] = table[i][j + 1];
			if(table[i + 1][j + 1] < table[i + 1][j])
				table[i + 1][j + 1] = table[i + 1][j];
		}

		printf("Case #%d: you can visit at most %d cities.\n", n_cases++, table[n][m]);
	}

	return 0;
}

