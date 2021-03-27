#include <cstdio>

#define N 200001

int main()
{
	int n_cases, n, k, score;
	char str[N];

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		scanf("%d %d", &n, &k);
		scanf("%s", str);

		score = 0;
		for(int i = 0; i < (n >> 1); ++i)
			score += str[i] != str[n - i - 1];
		
		printf("Case #%d: %d\n", c, score < k ? k - score : score - k);
	}

	return 0;
}

