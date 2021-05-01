#include <cstdio>
#include <algorithm>
#include <vector>

int main()
{
	int n_cases, n, k, g;

	std::vector<int> tickets;
	std::vector<int> p;

	scanf("%d", &n_cases);
	for(int c = 0; c < n_cases; ++c)
	{
		scanf("%d %d", &n, &k);

		tickets.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &tickets[i]);

		std::sort(tickets.begin(), tickets.end());

		p.push_back(tickets[0] - 1);
		for(int i = 1; i < n; ++i)
		{
			g = tickets[i] - tickets[i - 1];
			p.push_back(g >> 1);
			p.push_back(g - 1 - p.back());
		}
		p.push_back(k - tickets[n - 1]);

		std::sort(p.begin(), p.end());
		n = p.size();

		printf("Case #%d: %f\n", c + 1, double(p[n - 1] + p[n - 2]) / k);

		p.clear();
	}

	return 0;
}

