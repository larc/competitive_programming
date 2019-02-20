// 6. Balloons Colors

#include <cstdio>

int main()
{
	int bc, x, y, n, t;
	bool a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &x, &y);
		scanf("%d", &bc);
		a = x == bc;
		n -= 2;
		while(n--) scanf("%d", &bc);
		scanf("%d", &bc);
		b = y == bc;

		if(a && b)
			printf("BOTH\n");
		else if(a && !b)
			printf("EASY\n");
		else if(!a && b)
			printf("HARD\n");
		else
			printf("OKAY\n");
	}
	return 0;
}
