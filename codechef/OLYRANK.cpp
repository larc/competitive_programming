#include <cstdio>

int main()
{
	int n_cases, C[2], m;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		C[0] = C[1] = 0;
		for(int i = 0; i < 6; ++i)
		{
			scanf("%d", &m);
			C[i > 2] += m;
		}

		printf("%d\n", (C[0] < C[1]) + 1);
	}

	return 0;
}

