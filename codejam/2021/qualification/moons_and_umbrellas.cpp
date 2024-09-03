#include <cstdio>

int main()
{
	int n_cases, x, y, cost, n;
	char S[1001];

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		scanf("%d %d %s", &x, &y, S);

		n = 0;
		for(int i = 0; S[i]; ++i)
			if(S[i] != '?')
				S[n++] = S[i];

		cost = 0;
		for(int i = 1; i < n; ++i)
			if(S[i - 1] != S[i])
				cost += S[i] == 'J' ? x : y;

		printf("Case #%d: %d\n", c, cost);
	}

	return 0;
}

