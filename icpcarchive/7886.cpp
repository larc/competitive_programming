// 7886 - Assigning Teams

#include <cstdio>

int main()
{
	int a, b, c, d;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
	{
		a += d;
		b += c;
		if(a > b) printf("%d\n", a - b);
		else printf("%d\n", b - a);
	}

	return 0;
}

