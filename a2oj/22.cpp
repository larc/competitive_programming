// 22. Contest Hall Preparation

#include <cstdio>
#include <cstring>

int main()
{
	int t, n, m, i, j, a, x, s;
	int row[2][101];
	int uni[102];
	scanf("%d", &t);
	while(t--)
	{
		a = 0;
		for(i = 0; i < 102; i++) uni[i] = 0;
		scanf("%d %d", &n, &m);
		row[0][m] = row[1][m] = -1;
		scanf("%d", &row[a][0]);
		for(j = 1; j < m; j++)
		{
			scanf("%d", &row[a][j]);
			x = row[a][j] + 1;
			if(row[a][j] == row[a][j - 1]) uni[x]++;
		}
		n--;
		for(i = 0; i < n; i++)
		{
			j = 0;
			scanf("%d", &row[!a][j]);
			x = row[!a][j] + 1;
			if(row[!a][j] == row[a][j]) uni[x]++;
			if(row[!a][j] == row[a][j+1]) uni[x]++;

			for(j = 1; j < m; j++)
			{
				scanf("%d", &row[!a][j]);
				x = row[!a][j] + 1;
				if(row[!a][j] == row[!a][j - 1]) uni[x]++;
				if(row[!a][j] == row[a][j - 1]) uni[x]++;
				if(row[!a][j] == row[a][j]) uni[x]++;
				if(row[!a][j] == row[a][j+1]) uni[x]++;
			}
			a = !a;
		}
		s = 0;
		for(i = 1; i < 102; i++)
			s += uni[i] > 0?1:0;
		printf("%d\n", s);
	}
	return 0;
}
