#include <cstdio>
#include <algorithm>

int main()
{
	int n_cases, x, y, cost[2][2], n;
	char S[1001], CJ[2] = {'C', 'J'};

	auto cj = [&x, &y](const char & a, const char & b) -> int
	{
		if(a == b) return 0;
		return b == 'J' ? x : y;
	};

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		scanf("%d %d %s", &x, &y, S);

		cost[0][0] = 0;
		cost[1][0] = 0;

		n = 0;
		while(S[++n])
			for(int i = 0; i < 2; ++i)
			{
				char & ss = S[n] != '?' ? S[n] : CJ[i];
				char & cc = S[n - 1] != '?' ? S[n - 1] : CJ[0];
				char & jj = S[n - 1] != '?' ? S[n - 1] : CJ[1];

				cost[i][n & 1] = std::min(	cost[0][!(n & 1)] + cj(cc, ss),
											cost[1][!(n & 1)] + cj(jj, ss)
											);
			}

		printf("Case #%d: %d\n", c, std::min(cost[0][!(n & 1)], cost[1][!(n & 1)]));
	}

	return 0;
}

