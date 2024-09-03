#include <cstdio>

int sum(char * T)
{
	int s = 0;
	for(int i = 0; T[i]; ++i)
		s += T[i] - '0';

	return s;
}

int main()
{
	int n_cases, p, cheater;
	char T[100][10001];
	int S[10001];

	scanf("%d", &n_cases);
	scanf("%d", &p);

	for(int c = 1; c <= n_cases; ++c)
	{
		for(int i = 0; i < 100; ++i)
		{
			scanf("%s", T[i]);

			S[i] = sum(T[i]);
		}

		cheater = 0;
		for(int i = 1; i < 100; ++i)
			if(S[i] > S[cheater])
				cheater = i;

		printf("Case #%d: %d\n", c, cheater + 1);
	}

	return 0;
}

