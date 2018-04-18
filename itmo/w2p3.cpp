// Queue with Minimum

#include <cstdio>
#include <cstring>
#include <queue>

#define N 1000001

typedef std::pair<int, int> ii;

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	char c;
	int n, x, idx = 0;
	std::priority_queue<ii> m;
	std::queue<ii> q;

	bool removed[N];

	scanf("%d", &n);
	while(n--)
	{
		scanf(" %c", &c);
		if(c == '?')
		{
			while(removed[m.top().second]) m.pop();
			printf("%d\n", -m.top().first);
		}
		else if(c == '-')
		{
			removed[q.front().second] = 1;
			q.pop();
		}
		else
		{
			scanf("%d", &x);
			q.push(std::make_pair(-x, idx));
			m.push(std::make_pair(-x, idx));

			removed[idx++] = 0;
		}
	}

	return 0;
}

