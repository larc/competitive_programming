#include <cstdio>

int main()
{
	int n, m, d, C[1001], S = 0, p;
	int R[1001] = {};

	scanf("%d %d %d", &n, &m, &d);
	for(int i = 1; i <= m; ++i)
	{	
		scanf("%d", C + i);
		S += C[i];
	}
	
	p = 0;
	for(int i = 1; i <= m; ++i)
	{
		int & c = C[i];
	
		if(S <= n + 1 - p - d) p += d;
		else p = n + 1 - S;

		while(c--)
		{
			S--;
			R[p++] = i;
		}
		p--;
	}

	if(n + 1 - p > d)
	{
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");
	for(int i = 1; i <= n; ++i)
		printf("%d ", R[i]);
	putchar('\n');
	
	return 0;
}

