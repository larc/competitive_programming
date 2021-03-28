#include <cstdio>
#include <algorithm>
#include <functional>

#define mod(x) (x) % 1000000007

int main()
{
	int n_cases, n, sum;
	int P[100000];

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", P + i);

		std::sort(P, P + n, std::greater<int>());

		sum = 0;
		for(int i = 0; i < n; ++i)
		{
			if(P[i] - i <= 0) break;
			sum = mod(sum + P[i] - i);
		}

		printf("%d\n", sum);
	}

	return 0;
}

