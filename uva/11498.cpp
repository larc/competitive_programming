#include <cstdio>

int main()
{
	int k, n, m, x, y;
	while(scanf("%d", &k) != EOF && k)
	{
		scanf("%d %d", &n, &m);
		while(k--)
		{
			scanf("%d %d", &x, &y);
			if(x == n) printf("divisa\n");
			else if(y == m) printf("divisa\n");
			else if(x > n && y > m) printf("NE\n");
			else if(x > n && y < m) printf("SE\n");
			else if(x < n && y < m) printf("SO\n");
			else printf("NO\n");
		}
	}
	return 0;
}
