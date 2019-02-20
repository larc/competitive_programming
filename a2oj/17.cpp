// 17. Kids Love Candies

#include <cstdio>

int main()
{
	int t, n, k, c, s;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		s = 0;
		while(n--)
		{
			scanf("%d", &c);
			s += c/k;
		}
		printf("%d\n", s);
	}
	return 0;
}
