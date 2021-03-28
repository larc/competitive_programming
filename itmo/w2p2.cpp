// Queue

#include <cstdio>
#include <queue>

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	char c;
	int n, x;
	std::queue<int> q;

	scanf("%d", &n);
	while(n--)
	{
		scanf(" %c", &c);
		if(c == '-')
		{
			printf("%d\n", q.front());
			q.pop();
		}
		else
		{
			scanf("%d", &x);
			q.push(x);
		}
	}

	return 0;
}

