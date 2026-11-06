#include <cstdio>

char T[1002][1002];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", T[i] + 1);

	int p = 0;
	int D[5] = {};
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j)
	{
		int k = 0;
		if(T[i][j] == '.') continue;
		if(T[i - 1][j] == '#') ++k;
		if(T[i + 1][j] == '#') ++k;
		if(T[i][j - 1] == '#') ++k;
		if(T[i][j + 1] == '#') ++k;
		++D[k];
		p += 4 - k;
	}

	printf("%d", p);
	for(int i = 0; i < 5; ++i)
		printf(" %d", D[i]);
	printf("\n");

	return 0;
}
