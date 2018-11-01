#include <cstdio>
#include <cstring>

#define N 1025

int mat[N][N], ft[N][N], n;

void adjust(int i, const int & y, const int & v)
{
	while(i <= n)
	{
		for(int j = y; j <= n; j += j & -j)
			ft[i][j] += v;
		i += i & -i;
	}
}

int rsq(int i, const int & y)
{
	int r = 0;
	while(i)
	{
		for(int j = y; j; j -= j & -j)
			r += ft[i][j];
		i -= i & -i;
	}
	return r;
}

int main()
{
	char str[4];
	int n_cases, x1, y1, x2, y2, num, old[N];

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		memset(mat, 0, sizeof(mat));
		memset(ft, 0, sizeof(ft));

		scanf("%d", &n);
		while(scanf("%s", str) && str[0] != 'E')
		{
			if(str[1] == 'E')	// SET
			{
				scanf("%d %d %d", &x1, &y1, &num);
				x1++; y1++;

				adjust(x1, y1, num - mat[x1][y1]);
				mat[x1][y1] = num;
			}
			else	// SUM
			{
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				x1++; y1++; x2++; y2++;

				printf("%d\n", rsq(x2, y2) - rsq(x1 - 1, y2) - rsq(x2, y1 - 1) + rsq(x1 - 1, y1 - 1));
			}
		}
		
		putchar('\n');
	}

	return 0;
}

