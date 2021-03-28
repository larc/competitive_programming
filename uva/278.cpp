#include <cstdio>

int main()
{
	int c, m, n, r;
	char p;
	int Q[5] = {0, 1, 1, 2, 3};

	scanf("%d", &c);
	while(c--)
	{
		scanf(" %c %d %d", &p, &m, &n);
		switch(p)
		{
			case 'r': r = m > n ? n : m; break;
			case 'k': r = (m * n + 1) >> 1; break;
			case 'Q':
				m = m < n ? m : n;
				r = m > 4 ? m : Q[m];
				break;
			case 'K': r = ((m + 1) >> 1) * ((n + 1) >> 1); break;
		}
		printf("%d\n", r);
	}
	return 0;
}

