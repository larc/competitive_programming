#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define N 300000

struct charge
{
	int a, t;
};

int main()
{
	int n_cases, n, time;
	charge P[N];
	std::vector<int> order; order.reserve(N);

	auto tcmp = [&P](const int i, const int j)
	{
		return P[i].t < P[j].t;
	};

	auto acmp = [&P](const int i, const int j)
	{
		return P[i].a < P[j].a;
	};

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

		std::sort(order.begin(), order.end(), tcmp);
		std::priority_queue<int, std::vector<int>, decltype(acmp)> Q(acmp);

		time = 0;
		for(const int i: order)
		{
			charge & p = P[i];

			if(time + p.a > p.t && !Q.empty())
			{
				charge & q = P[Q.top()];
				if(q.a > p.a && time + p.a - q.a <= p.t)
				{
					time -= q.a;
					q.a = -1; --n;
					Q.pop();
				}
			}

			if(time + p.a <= p.t)
			{
				time += p.a;
				Q.push(i);
			}
			else
			{
				p.a = -1; --n;
			}
		}

		printf("%d\n", n);

		time = 0;
		for(const int i: order)
		{
			charge & p = P[i];
			if(p.a >= 0)
			{
				printf("%d %d %d\n", i + 1, time, time + p.a);
				time += p.a;
			}
		}

		order.clear();
	}

	return 0;
}

