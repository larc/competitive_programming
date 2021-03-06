#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m, k, a;
	
	scanf("%d %d %d", &n, &m, &k);
	
	vector<pair<int, int> > A(n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		A[i] = {a, i};
	}
	
	sort(A.begin(), A.end());
	bool V[n] = {};
	
	long long sum = 0;
	int p = m * k;
	for(int i = n - 1; i >= 0 && p--; i--)
	{
		sum += A[i].first;
		V[A[i].second] = 1;
	}
	
	printf("%lld\n", sum);

	p = 0; k--;
	for(int i = 0; i < n && k; ++i)
	{
		p += V[i];
		if(V[i] && p % m == 0)
		{
			printf("%d ", i + 1);
			k--;
		}
	}
	
	putchar('\n');
	return 0;
}

