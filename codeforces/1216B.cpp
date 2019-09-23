#include <cstdio>
#include <algorithm>

#define N 1000

int main()
{
	int a[N], s[N], n, shots;

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		s[i] = i;
	}
	
	std::sort(s + 1, s + n + 1, [&a](const int & i, const int & j) { return a[i] > a[j]; });

	shots = 1;
	for(int i = 2; i <= n; i++)
		shots += a[s[i]] * (i - 1) + 1;

	printf("%d\n", shots);
	for(int i = 1; i < n; i++)
		printf("%d ", s[i]);
	printf("%d\n", s[n]);

	return 0;
}

