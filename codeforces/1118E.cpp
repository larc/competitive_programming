#include <cstdio>

int main()
{
	long long n, m;
	scanf("%lld %lld", &n, &m);
	
	if(n > m * (m - 1))
	{
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	for(int i = 1; i <= m; ++i)
	for(int j = i + 1; j <= m; ++j)
	{
		if(n--) printf("%d %d\n", i, j);
		if(!n) return 0;

		if(n--) printf("%d %d\n", j, i);
		if(!n) return 0;
	}

	return 0;
}

