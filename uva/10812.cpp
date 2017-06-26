#include <cstdio>
#include <cmath>

int main()
{
	int s, d, c, y, x;
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d %d", &s, & d);
		y = (s - d) / 2;
		x = s - y;
		if(x + y != s || std::abs(x - y) != d || y < 0 || x < 0) printf("impossible\n");
		else
		{
			if(x > y) printf("%d %d\n", x, y);
			else printf("%d %d\n", y, x);
		}
	}
	return 0;
}

