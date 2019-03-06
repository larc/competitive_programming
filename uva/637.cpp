// 637 - Booklet Printing

#include <cstdio>

int main()
{
	int n, i, j, s;
	while(scanf("%d", &n) != EOF && n)
	{
		printf("Printing order for %d pages:\n", n);

		s = i = 1;
		j = n & 3 ? ((n >> 2) + 1) << 2 : n;

		while(i <= n && i < j)
		{
			if(j <= n) printf("Sheet %d, front: %d, %d\n", s, j, i);
			else printf("Sheet %d, front: Blank, %d\n", s, i);
			i++; j--;

			if(i <= n)
			{
				if(j <= n) printf("Sheet %d, back : %d, %d\n", s, i, j);
				else printf("Sheet %d, back : %d, Blank\n", s, i);
				i++; j--;
			}

			s++;
		}
	}

	return 0;
}

