#include <cstdio>
#include <algorithm>

int closest_sum(const int * A, const int n, const int q)
{
	const int i = std::lower_bound(A, A + n, q) - A;
	if(i == n) return n - 1;
	if(i == 0) return 0;
	return i;
}

int main()
{
	int A[1000];
	int m, n, q, closest, n_case = 0;

	auto update_closest = [&closest, &q](const int sum)
	{
		if(std::abs(q - sum) < std::abs(q - closest))
			closest = sum;
	};

	while(scanf("%d", &n) != EOF && n)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", A + i);

		std::sort(A, A + n);

		printf("Case %d:\n", ++n_case);

		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &q);
			closest = 100000000;
			for(int i = 0; i < n; ++i)
			{
				const int j = closest_sum(A, n, q - A[i]);
				if(j != i	) update_closest(A[i] + A[j]);
				if(j > 0	) update_closest(A[i] + A[j - 1]);
				if(j < n + 1) update_closest(A[i] + A[j + 1]);
			}

			printf("Closest sum to %d is %d.\n", q, closest);
		}
	}

	return 0;
}

