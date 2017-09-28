// 11057 - Exact Sum

#include <cstdio>
#include <algorithm>

#define N 10000

int main()
{
	int n, m, a, b, s;
	int books[N];

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", books + i);

		scanf("%d", &m);

		std::sort(books, books + n);

		a = 0; b = 10000000;
		int i = 0, j = n - 1;
		while(i < j)
		{
			s = books[i] + books[j];
			if(s == m)
			{
				if(books[j] - books[i] < b - a)
				{
					a = books[i];
					b = books[j];
				}
				i++; j--;
			}
			else if(s < m) i++;
			else j--;
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
	}

	return 0;
}
