#include <cstdio>
#include <algorithm>
#include <vector>

#define N 300000

struct charge
{
	int a, t, l, r;
};

int main()
{
	int n_cases, n, time;
	charge P[N];
	std::vector<int> order; order.reserve(N);
	std::vector<int> valid; valid.reserve(N);

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &P[i].a);
		for(int i = 0; i < n; ++i)
			scanf("%d", &P[i].t);

		for(int i = 0; i < n; ++i)
			order.push_back(i);

		std::sort(order.begin(), order.end(), [&P](const int & i, const int & j)
			{
				return P[i].a == P[j].a ? P[i].t < P[j].t : P[i].a < P[j].a;
			});

		time = 0;
		for(const int & i: order)
		{
			charge & p = P[i];
			if(time + p.a <= p.t)
			{
				p.l = time;
				time += p.a;
				p.r = time;
				valid.push_back(i);
			}
		}

		printf("%lu\n", valid.size());
		for(const int & i: valid)
			printf("%d %d %d\n", i + 1, P[i].l, P[i].r);

		order.clear();
		valid.clear();
	}

	return 0;
}

