#include <cstdio>
#include <numeric>
#include <algorithm>

#define M 100000

struct query_t
{
	int x, y;

	bool operator < (const query_t & q) const
	{
		return x > q.x;
	}
};

int main()
{
	int n_cases, m;
	query_t Q[M];
	long long sum, rem, n, lcm;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%lld %d", &n, &m);
		for(int i = 0; i < m; ++i)
			scanf("%d %d", &Q[i].x, &Q[i].y);

		std::sort(Q, Q + m);

		sum = 0;
		lcm = 1;
		rem = n;
		for(int i = 0; i < m; ++i)
		{
			const auto & q = Q[i];
			lcm = std::lcm(lcm, q.y);
			sum += q.x * (rem -  n / lcm);
			rem = n / lcm;
		}

		printf("%lld\n", sum);
	}

	return 0;
}

