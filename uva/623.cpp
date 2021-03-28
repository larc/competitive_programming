// 623 - 500!

#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 1001
#define M 2600

char fact[N][M];
int size[N];

void to_char(char * num, int n)
{
	std::reverse(num, num + n);
	num[n] = '\0';
	while(n--) num[n] += '0';
}

void calc_all_fact()
{
	memset(fact, 0, sizeof(fact));
	memset(size, 0, sizeof(size));

	fact[0][0] = '1'; fact[0][1] = '\0';

	int x, k;
	char d, r;

	fact[1][0] = 1;	size[1] = 1;
	for(int i = 2; i < N; ++i)
	{
		x = i; k = 0;
		while(x)
		{
			d = x % 10;
			x /= 10;

			for(int j = 0; j < size[i - 1]; ++j)
			{
				r = fact[i - 1][j] * d;
				fact[i][j + k] += r;
				fact[i][j + k + 1] += fact[i][j + k] / 10;
				fact[i][j + k] %= 10;
			}
			k++;
		}

		size[i] = size[i - 1] + k - 1 + (fact[i][size[i - 1] + k - 1] != 0);

		to_char(fact[i - 1], size[i - 1]);
	}

	to_char(fact[N - 1], size[N - 1]);
}

int main()
{
	calc_all_fact();

	int n;
	while(scanf("%d", &n) != EOF)
	{
		printf("%d!\n", n);
		printf("%s\n", fact[n]);
	}

	return 0;
}

