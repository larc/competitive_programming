#include <cstdio>

int main()
{
	int n, m, u, v;
	int d[100'001] = {};

	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d %d", &u, &v);
		++d[u]; ++d[v];
	}

	m = 0;
	for(int i = 1; i <= n; ++i)
		if(d[i] & 1) ++m;

	if(!m) printf("CIRCUITO\n");
	else if(m == 2) printf("CAMINO\n");
	else printf("IMPOSIBLE\n");

	return 0;
}

