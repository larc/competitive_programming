#include <cstdio>
#include <algorithm>

int rec[101][101];

int main()
{
	int n, i, j, k, max, d;
	int dp; 
	while(scanf("%d", &n) != EOF)
	{
		for(i = 0; i < n; ++i)
		for(j = 1; j <= n; ++j)
			scanf("%d", &rec[i][j]);
		
		for(i = 0; i < n; ++i)
		for(j = 1; j <= n; ++j)
			rec[i][j] += rec[i][j - 1];
		
		max = rec[0][1];
		for(i = 0; i < n; ++i)
		for(j = i + 1; j <= n; ++j)
		{
			dp = 0;
			for(k = 1; k <= n; ++k)
			{
				d = rec[k][j] - rec[k][i];
				dp = std::max(dp + d, d);
				if(dp > max) max = dp;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}

