#include <cstdio>
#include <algorithm>

#define N 100000

int S[N], A[N], ans[N], rev[N], size, min;

void dfs(int m, int n, int k)
{
	if(n >= 0 && m >= A[n])
	{
		m -= A[n];
		while(n >= 0)	
			rev[k++] = n--;
	}

	if(n < 0 && m < min)
	{
		min = m;

		size = k;
		for(int i = 0; i < k; i++)
			ans[i] = rev[k - i - 1];
	}
	
	int u;
	while(n >= 0 && m - S[n] >= 0)
	{
		rev[k] = n;
		u = std::upper_bound(S, S + n, m - S[n]) - S;

		dfs(m - S[n], u - 1, k + 1);
		
		n--;
	}
}

int main()
{
	int m, n;

	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; i++)
		scanf("%d", S + i);
	
	A[0] = S[0];
	for(int i = 1; i < n; i++)
		A[i] = A[i - 1] + S[i];
	
	min = m + 1;
	dfs(m, n - 1, 0);

	fprintf(stderr, "max: %d\n", m - min);

	printf("%d\n", size);
	for(int i = 0; i < size; i++)
		printf("%d ", ans[i]);
	putchar('\n');

	return 0;
}

