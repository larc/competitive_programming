#include <cstdio>

#define N 102
#define M 1000000

int main()
{
	int n, m;
	int d[N][N], p[M], v[M];
	char line[N];

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", line + 1);
		for(int j = 1; j <= n; ++j)
			d[i][j] = line[j] == '1' ? 1 : N;

		d[i][i] = 0;
	}

	// Floyd-Warshall algorithm
	for(int k = 1; k <= n; ++k)
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= n; ++j)
		if(d[i][j] > d[i][k] + d[k][j])
			d[i][j] = d[i][k] + d[k][j];

	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
		scanf("%d", p + i);

	n = 0;
	v[n++] = p[0];

	int a = 0;
	int b = 1;
	int c = 2;
	while(c < m)
	{
		const int i = p[a];
		const int k = p[b];
		const int j = p[c];
		if(d[i][j] != d[i][k] + d[k][j] || i == j)
		{
			a = b;
			v[n++] = k;
		}

		b++; c++;
	}

	printf("%d\n", n + 1);
	for(int i = 0; i < n; ++i)
		printf("%d ", v[i]);
	printf("%d\n", p[m - 1]);

	return 0;
}

