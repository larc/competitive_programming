// 1056 - Factors and Multiples

#include <cstdio>
#include <cstring>

#define N 200 // max number of nodes A and B
#define M 100 // max number edges adjacent list


int S[N]; // nodes values
int A[N][M + 1]; // adjacent list
bool visited[N];
int match[N];

int & size(const int i)
{
	return A[i][M];
}

bool augmenting_path(const int a) // dfs: mcbm
{
	if(visited[a]) return 0;
	visited[a] = 1;

	int b;
	for(int i = 0; i < size(a); ++i)
	{
		b = A[a][i];
		if(match[b] == -1 || augmenting_path(match[b]))
		{
			match[b] = a;
			match[a] = b;
			return 1;
		}
	}

	return 0;
}

int main()
{

	int c, t, n, m, a, b, mcbm;

	scanf("%d", &t); c = 0;
	while(t--)
	{
		scanf("%d", &n);
		for(a = 0; a < n; ++a)
			scanf("%d", &S[a]);

		scanf("%d", &m);
		m += n;
		for(b = n; b < m; ++b)
			scanf("%d", &S[b]);

		// graph: adjacent list A to B only
		for(a = 0; a < m; ++a)
			size(a) = 0;

		for(b = n; b < m; ++b)
		for(a = 0; a < n; ++a)
			if(!S[b] || (S[a] && !(S[b] % S[a])))
				A[a][size(a)++] = b;

		memset(match, -1, sizeof(match));

		mcbm = 0;
		for(a = 0; a < n; ++a)
			if(match[a] == -1)
			{
				memset(visited, 0, sizeof(visited));
				mcbm += augmenting_path(a);
			}

		printf("Case %d: %d\n", ++c, mcbm);
	}

	return 0;
}

