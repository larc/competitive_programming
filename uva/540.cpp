// 540 - Team Queue

#include <cstdio>
#include <cstring>
#include <queue>

#define N 1000

int main()
{
	char str[8];
	int team[N * N], n, m, x;
	int Q[N][N], E[N], D[N];
	bool qteam[N];

	int k = 1;
	while(scanf("%d", &n) && n)
	{
		printf("Scenario #%d\n", k++);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			while(m-- && scanf("%d", &x))
				team[x] = i;
		}

		memset(qteam, 0, sizeof(qteam));
		memset(E, 0, sizeof(E));
		memset(D, 0, sizeof(D));

		std::queue<int> q;
		while(scanf("%s", str) && str[0] != 'S')
		{
			if(str[0] == 'E')
			{
				scanf("%d", &x);

				n = team[x];
				if(!qteam[n])
				{
					q.push(n);
					qteam[n] = 1;
				}

				Q[n][E[n]++] = x;
			}
			else
			{
				n = q.front();
				printf("%d\n", Q[n][D[n]++]);

				if(E[n] == D[n])
				{
					qteam[n] = 0;
					q.pop();
				}
			}
		}

		putchar('\n');
	}

	return 0;
}

