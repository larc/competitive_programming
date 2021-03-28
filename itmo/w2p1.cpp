// Stack

#include <cstdio>
#include <stack>

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	char c;
	int n, x;
	std::stack<int> s;

	scanf("%d", &n);
	while(n--)
	{
		scanf(" %c", &c);
		if(c == '-')
		{
			printf("%d\n", s.top());
			s.pop();
		}
		else
		{
			scanf("%d", &x);
			s.push(x);
		}
	}

	return 0;
}

