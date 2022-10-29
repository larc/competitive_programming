#include <cstdio>
#include <algorithm>

int main()
{
	int n_cases, length, n, a;
	int earliest, latest;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		earliest = latest = 0;

		scanf("%d %d", &length, &n);
		while(n--)
		{
			scanf("%d", &a);
			earliest = std::max(earliest, std::min(a, length - a));
			latest = std::max(latest, std::max(a, length - a));
		}
		printf("%d %d\n", earliest, latest);
	}

	return 0;
}

