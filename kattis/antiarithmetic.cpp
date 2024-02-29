#include <cstdio>

#define N 10000

int S[N], P[N];

bool antiarithmetic(const int n)
{
	for(int i = 0; i < n; ++i)
	for(int j = i + 1; j < n; ++j)
	{
		const int k = 2 * S[i] - S[j];
		if(k < n && k >= 0 && P[k] < i)
			return false;
	}

	return true;
}

int main()
{
	int n;
	while(scanf("%d:", &n), n)
	{
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", S + i);
			P[S[i]] = i;
		}

		printf("%s\n", antiarithmetic(n) ? "yes" : "no");
	}

	return 0;
}

