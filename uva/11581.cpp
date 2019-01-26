// 11581 - Grid Successors

#include <cstdio>
#include <cstring>

int main()
{
	char g[5][5] = {}, h[5][5] = {};
	int n, r, c;

	scanf("%d", &n);
	while(n--)
	{
		for(int i = 1; i <= 3; i++)
		{
			scanf("%s", g[i] + 1);
			for(int j = 1; j <= 3; j++)
				g[i][j] -= '0';
		}
		
		r = -1;
		while(true)
		{
			c = 0;
			for(int i = 1; i <= 3; i++)
			for(int j = 1; j <= 3; j++)
			{
				c += g[i][j];
				h[i][j] = (g[i - 1][j] + g[i + 1][j] + g[i][j + 1] + g[i][j - 1]) & 1;
			}
			
			memcpy(g, h, sizeof(g));

			if(!c) break;
			r++;
		}

		printf("%d\n", r);
	}

	return 0;
}

