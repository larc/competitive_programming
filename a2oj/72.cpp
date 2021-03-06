// 72. Ahmed Aly 

#include <cstdio>

int main()
{
	int n, x, y, z;
	char op;

	scanf("%d", &n);
	for(int c = 1; c <= n; ++c)
	{
		scanf("%d %c %d = %d", &x, &op, &y, &z);

		if(op == '-') printf("Case %d: %s\n", c, x - y == z ? "YES" : "NO");
		else printf("Case %d: %s\n", c, x + y == z ? "YES" : "NO");
	}

	return 0;
}

