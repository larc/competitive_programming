#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	int g[101][101];
	int m, n, i, j;

	while(scanf("%d %d", &n, &m) && n)
	{
		memset(g, 0, sizeof(g));
		while(m--)
		{
			scanf("%d %d", &i, &j);
			g[i][++g[i][0]] = j;
			g[0][j]++;
		}

		queue<int> q;
		for(i = 1; i <= n; i++)
			if(!g[0][i]) q.push(i);

		while(n--)
		{
			i = q.front();
			printf("%d", i);
			if(n) printf(" ");
			q.pop();
			for(j = 1; j <= g[i][0]; j++)
				if(!(--g[0][g[i][j]]))
					q.push(g[i][j]);
		}
		printf("\n");
	}
	return 0;
}

