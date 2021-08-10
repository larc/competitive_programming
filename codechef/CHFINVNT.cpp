#include <cstdio>
#include <algorithm>

int main()
{
	int n_cases, n, p, k, m;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d %d", &n, &p, &k);
		n = n - 1;
		m = std::min(n % k, p % k - 1);
		printf("%d\n", (m + 1) * (n / k + 1) + (p % k - m - 1) * (n / k) + (p / k + 1));
	}

	return 0;
}

