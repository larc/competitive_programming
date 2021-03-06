// 14. The New President

#include <cstdio>
#include <cstring>

int main()
{
	int t, c, v, i, j, a, b;
	int p[101][101];
	int g[101];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &c, &v);
		memset(g, 0, sizeof(g));

		for(i = 0; i < v; ++i)
		{
			scanf("%d", &p[i][0]);
			g[p[i][0]]++;
			for(j = 1; j < c; ++j)
				scanf("%d", &p[i][j]);
		}
		a = b = 0;
		for(j = 1; j <= c; ++j)
		{
			if(g[j] > g[a])
			{
				b = a;
				a = j;
			}
			else if(g[j] > g[b])
				b = j;
		}
		if(g[a] > v/2)
			printf("%d 1\n", a);
		else
		{
			g[a] = g[b] = 0;
			for(i = 0; i < v; ++i)
				for(j = 0; j < c; ++j)
					if(p[i][j] == a || p[i][j] == b)
					{
						g[p[i][j]]++;
						break;
					}

			a = g[a] > g[b] ? a : b;
			printf("%d 2\n", a);
		}
	}

	return 0;
}
