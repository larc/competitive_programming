#include <cstdio>

int main()
{
	int n_cases, val, first, second;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		first = second = 10000;
		for(int i = 0; i < 10; i++)
		{
			scanf("%d", &val);
			if(val < first)
			{
				second = first;
				first = val;
			}
			else if(val < second)
				second = val;
		}

		printf("%d\n", second);
	}

	return 0;
}

