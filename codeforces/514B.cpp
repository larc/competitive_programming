#include <cstdio>
#include <set>
#include <utility>

int gcd(const int a, const int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n, x, y, a, b, d;
	std::set<std::pair<int, int> > shoots;

	bool vertical = 0;

	scanf("%d %d %d", &n, &x, &y);
	while(n--)
	{
		scanf("%d %d", &a, &b);

		a -= x; b -= y;
		if(!a) vertical = 1;
		else
		{
			d = gcd(b, a);
			shoots.insert({b / d, a / d});
		}
	}

	printf("%lu\n", shoots.size() + vertical);

	return 0;
}

