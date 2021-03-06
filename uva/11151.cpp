// 11151 - Longest Palindrome

#include <cstdio>
#include <algorithm>

#define N 1002

int main()
{
	int n_cases, n, j;
	int len[N][N];
	char str[N];

	scanf("%d", &n_cases);
	fgets(str, N, stdin);

	while(n_cases--)
	{
		fgets(str, N, stdin);

		for(n = 0; str[n] != '\n'; ++n)
		{
			len[n][n] = 1;
			len[n][n + 1] = 1 + (str[n] == str[n + 1]);
		}
		
		for(int k = 2; k < n; ++k)
		for(int i = 0; i + k < n; ++i)
		{
			j = i + k;
			if(str[i] == str[j]) len[i][j] = 2 + len[i + 1][j - 1];
			else len[i][j] = std::max(len[i][j - 1], len[i + 1][j]);
		}

		printf("%d\n", n ? len[0][n - 1] : 0);
	}

	return 0;
}

