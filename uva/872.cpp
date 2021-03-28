// 872 - Ordering

#include <cstdio>
#include <cstring>

#define N 27

bool G[N][N];
int degree[N], sort[N];
bool V[N], S[N], b;

void top_sort(const int & k, const int & n)
{
	if(k == n)
	{
		b = 1;

		putchar(sort[0] + 'A');
		for(int i = 1; i < n; ++i)
			printf(" %c", sort[i] + 'A');
		putchar('\n');
		return;
	}

	for(int i = 0; i < N; ++i)
	{
		if(V[i] && !S[i] && !degree[i])
		{
			S[i] = 1;
			for(int j = 0; j < N; ++j)
				if(G[i][j]) degree[j]--;

			sort[k] = i;
			top_sort(k + 1, n);

			S[i] = 0;
			for(int j = 0; j < N; ++j)
				if(G[i][j]) degree[j]++;
		}
	}
}

int main()
{
	char str[256];
	int n_cases, u, v, n;

	scanf("%d", &n_cases);
	fgets(str, sizeof(str), stdin);

	while(n_cases--)
	{
		memset(G, 0, sizeof(G));
		memset(degree, 0, sizeof(degree));

		fgets(str, sizeof(str), stdin);

		memset(V, 0, sizeof(V));
		fgets(str, sizeof(str), stdin);
		for(n = 0; str[n << 1]; ++n)
			V[str[n << 1] - 'A'] = 1;

		memset(str, 0, sizeof(str));
		fgets(str, sizeof(str), stdin);
		for(int i = 0; str[i]; i += 4)
		{
			u = str[i] - 'A';
			v = str[i + 2] - 'A';
			G[u][v] = 1;
			degree[v]++;
		}

		b = 0;
		memset(S, 0, sizeof(S));
		top_sort(0, n);

		if(!b) printf("NO\n");

		if(n_cases) putchar('\n');
	}

	return 0;
}

