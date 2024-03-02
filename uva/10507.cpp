// 10507 - Waking up brain

#include <cstdio>
#include <cstring>
#include <queue>

#define N 26
#define idx(i) str[i] - 'A'

int main()
{
	char G[N][N];
	int size[N];
	int wake_time[N];
	int waked_conn[N];

	int n, m, time;
	char str[4];

	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(wake_time, -1, sizeof(wake_time));
		memset(waked_conn, 0, sizeof(waked_conn));
		memset(size, 0, sizeof(size));

		std::queue<int> q;

		scanf("%s", str);
		wake_time[idx(0)] = 0; q.push(idx(0));
		wake_time[idx(1)] = 0; q.push(idx(1));
		wake_time[idx(2)] = 0; q.push(idx(2));

		while(m--)
		{
			scanf("%s", str);
			G[idx(0)][size[idx(0)]++] = idx(1);
			G[idx(1)][size[idx(1)]++] = idx(0);
		}

		time = 0; n -= 3;
		while(!q.empty())
		{
			m = q.front(); q.pop();
			time = wake_time[m];

			for(int i = 0; i < size[m]; ++i)
			{
				const int u = G[m][i];
				if(wake_time[u] < 0)
				{
					waked_conn[u]++;
					if(waked_conn[u] == 3)
					{
						n--;
						wake_time[u] = time + 1;
						q.push(u);
					}
				}
			}
		}

		if(!n) printf("WAKE UP IN, %d, YEARS\n", time);
		else printf("THIS BRAIN NEVER WAKES UP\n");
	}

	return 0;
}

