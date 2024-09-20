// 10880 - Colin and Ryan

#include <cstdio>
#include <algorithm>
#include <vector>


int main()
{
	int c, q, r, n;
	std::vector<int> div;
	div.reserve(100000);

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d %d", &c, &r);
		c -= r;

		printf("Case #%d:", i);

		for(int j = 1; j * j <= c; ++j)
		{
			if(c % j) continue;

			q = c / j;
			if(j > r) printf(" %d", j);
			if(q != j && q > r) div.push_back(q);
		}

		std::reverse(begin(div), end(div));
		for(int x: div)
			printf(" %d", x);

		c ? printf("\n") : printf(" 0\n");

		div.clear();
	}

	return 0;
}

