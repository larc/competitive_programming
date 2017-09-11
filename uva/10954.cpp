#include <cstdio>
#include <queue>

#define N 5000

int main()
{
	std::priority_queue<int> q;

	int n, cost, i;
	while(scanf("%d", &n), n)
	{
		while(n--)
		{
			scanf("%d", &i);
			q.push(-i);
		}

		cost = 0;
		while(!q.empty())
		{
			i = -q.top(); q.pop();
			if(!q.empty())
			{
				i += -q.top(); q.pop();
				cost += i;
				q.push(-i);
			}
		}

		printf("%d\n", cost);
	}
	
	return 0;
}

