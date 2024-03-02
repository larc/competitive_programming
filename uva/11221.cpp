// 11221 - Magic square palindromes.

#include <cstdio>
#include <cmath>

bool is_matrix_pal(char ** M, const int k)
{
	for(int i = 0; i < k; ++i)
	for(int j = 0; j < k; ++j)
	{
		if(M[i][j] != M[j][i]) return 0;
		if(M[i][j] != M[k - i - 1][k - j - 1]) return 0;
	}

	return 1;
}

int main()
{
	char str[10002], * M[100];
	int n_cases, n, k;

	scanf("%d\n", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		fgets(str, sizeof(str), stdin);
		printf("Case #%d:\n", c);

		n = 0;
		for(int i = 0; str[i]; ++i)
			if('a' <= str[i] && str[i] <= 'z')
				str[n++] = str[i];
		str[n] = 0;

		k = sqrt(n);

		M[0] = str;
		for(int i = 1; i < k; ++i)
			M[i] = M[i - 1] + k;

		if(k * k != n || !is_matrix_pal(M, k))
			printf("No magic :(\n");
		else
			printf("%d\n", k);
	}

	return 0;
}

