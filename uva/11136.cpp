// 11136 - Hoax or what

#include <cstdio>
#include <set>

int main()
{
	int n, k, b;
	long long p;
	std::multiset<int> bills;

	while(scanf("%d", &n), n)
	{
		p = 0;
		while(n--)
		{
			scanf("%d", &k);
			while(k--)
			{
				scanf("%d", &b);
				bills.insert(b);
			}

			p += *bills.rbegin() - *bills.begin();
			bills.erase(bills.begin());
			bills.erase(--bills.end());
		}

		printf("%lld\n", p);
		bills.clear();
	}

	return 0;
}

