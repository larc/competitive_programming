#include <cstdio>
#include <cmath>

#define N 100000
#define M 17

int num[N], st[M][N];

void init_st(const int & n)
{
	for(int i = 0; i < n; ++i)
		st[0][i] = i;
	
	int k;
	for(int i = 1; (1 << i) <= n; ++i)
	{
		k = 1 << (i - 1);
		for(int j = 0; j + (1 << i) - 1 < n; ++j)
		{
			const int & a = st[i - 1][j];
			const int & b = st[i - 1][j + k];
			st[i][j] = num[a] < num[b] ? a : b;
		}
	}
}

int rmq(const int & a, const int & b)
{
	if(b < a) return rmq(b, a);
	
	int k = log2(b - a + 1);
	const int & i = st[k][a];
	const int & j = st[k][b - (1 << k) + 1];
	
	return num[i] < num[j] ? num[i] : num[j];
}

int main()
{
	int n, q, a, b;

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", num + i);
		
		init_st(n);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &a, &b);
			printf("%d\n", rmq(a, b));
		}
	}

	return 0;
}

