// 2904 - Building a Field

#include <cstdio>
#include <algorithm>

#define N 100001

int main()
{
	int n, t, c;
	int T[N];

	scanf("%d", &n);

	T[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &t);
		T[i] = T[i - 1] + t;
	}

	if(T[n] & 1)
	{
		printf("N\n");
		return 0;
	}

	t = T[n] >> 1;

	c = 0;
	for(int i = 0; i < n && T[i] < t; ++i)
		c += std::binary_search(T, T + n, (T[i] + t) % T[n]);

	if(c > 1) printf("Y\n");
	else printf("N\n");

	return 0;
}

