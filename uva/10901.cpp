// 10901 - Ferry Loading III

#include <cstdio>
#include <queue>
#include <utility>

#define arrival front().first
#define M 10000

int main()
{
	char side[6];
	int unloaded[M];
	int i, j, c, n, m, t, time;

	scanf("%d", &c);
	while(c--)
	{
		std::queue<std::pair<int, int> > q[2];	// 0: left | 1: right
		scanf("%d %d %d", &n, &t, &m);

		for(i = 0; i < m; ++i)
		{
			scanf("%d %s", &time, side);
			q[side[0] == 'r'].push({time, i});
		}

		i = 0;
		time = 0;

		while(1)
		{
			j = 0;
			while(j < n && !q[i].empty() && q[i].arrival <= time)
			{
				unloaded[q[i].front().second] = time + t;
				q[i].pop();
				j++;
			}

			if(j) { time += t; i = !i; }
			else
			{
				if(q[0].empty() && q[1].empty()) break;

				if(!q[i].empty() && !q[!i].empty())
					j = q[!i].arrival < q[i].arrival ? !i : i;
				else if(!q[0].empty()) j = 0;
				else j = 1;

				time = std::max(time, q[j].arrival) + (i != j) * t;
				i = j;
			}
		}

		for(i = 0; i < m; ++i)
			printf("%d\n", unloaded[i]);
		if(c) putchar('\n');
	}

	return 0;
}

