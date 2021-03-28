#include <cstdio>

int main()
{
	int n_cases, n, a, i, x;
	bool b;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);

		b = true;
		i = 0; x = -5;
		while(i++ < n)
		{
			scanf("%d", &a);
			if(a)
			{
				if(i - x < 6)
				{
					b = false;
					break;
				}
				x = i;
			}
		}
		while(i++ < n)
			scanf("%d", &a);

		printf("%s\n", b ? "YES" : "NO");
	}

	return 0;
}

