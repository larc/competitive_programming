#include <cstdio>
#include <map>

#define N 200000

int gcd(const int & a, const int & b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	std::map<std::pair<int, int>, int> m;
	int n, count, d;
	int a[N], b;
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);
		
	count = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &b);

		if(!b && !a[i])
		{
			count++;
			continue;
		}

		if(!a[i]) continue;

		if(!b) m[{0, 0}]++;
		else
		{
			d = gcd(a[i], b);
			m[{b / d, a[i] / d}]++;
		}
	}
	
	d = 0;
	for(auto & p: m)
		if(p.second > d)
			d = p.second;
	
	printf("%d\n", count + d);

	return 0;
}

