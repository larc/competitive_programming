// 324 - Factorial Frequencies

#include <cstdio>
#include <cstring>

#define N 367
#define M 782

char fact[N][M];
int size[N];
int freq[10];

void calc_all_fact()
{
	memset(fact, 0, sizeof(fact));
	memset(size, 0, sizeof(size));

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
	}
}

int main()
{
	calc_all_fact();

	int n;
	while(scanf("%d", &n), n)
	{
		printf("%d! --\n", n);

		memset(freq, 0, sizeof(freq));
		for(int i = 0; i < size[n]; ++i)
			freq[fact[n][i]]++;

		for(int i = 0; i < 10; ++i)
			printf("   (%d)%4d%c", i, freq[i], i % 5 == 4 ? '\n' : ' ');
	}

	return 0;
}

