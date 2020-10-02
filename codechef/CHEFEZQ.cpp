#include <cstdio>

long long first_day(const int * Q, const int & n, const int & k)
{
	long long r = 0;
	for(int i = 1; i <= n; i++)
	{
		r += Q[i];
		
		if(k > r)
			return i;

		r -= k;
	}

	return n + r / k + 1;
}

int main()
{
	int T, n, k, Q[100001];

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++)
			scanf("%d", Q + i);

		printf("%lld\n", first_day(Q, n, k));
	}
	return 0;
}

