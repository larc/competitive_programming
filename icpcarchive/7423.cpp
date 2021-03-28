//7423 - Assigning Workstations

#include <cstdio>
#include <algorithm>
#include <queue>

#define N 300000

int main()
{
	int n, m, unlcks;
	std::pair<int, int> res[N];

	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d %d", &res[i].first, &res[i].second);

		std::sort(res, res + n);

		unlcks = 0;
		std::priority_queue<int> q;

		for(int i = 0; i < n; ++i)
		{
			std::pair<int, int> & p = res[i];

			while(!q.empty() && p.first > -q.top() + m)
				q.pop();

			if(!q.empty() && p.first >= -q.top())
			{
				q.pop();
			}
			else unlcks++;

			q.push(-(p.first + p.second));
		}

		printf("%d\n", n - unlcks);
	}

	return 0;
}

