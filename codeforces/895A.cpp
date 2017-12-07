#include <cstdio>
#include <cmath>

#define N 360

int main()
{
	int a[N];
	int sum[N];
	int n;
	scanf("%d %d", &n, a);
	sum[0] = a[0];
	for(int i = 1; i < n; i++)
	{
		scanf("%d", a + i);
		sum[i] = sum[i - 1] + a[i];
	}

	int s, min = 360;
	for(int i = 0; i < n; i++)
	for(int j = i; j < n; j++)
	{
		s = sum[j] - sum[i] + a[i];
		s = abs(s + s - 360);
		if(s < min) min = s;
	}

	printf("%d\n", min);

	return 0;
}

