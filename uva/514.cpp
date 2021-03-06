#include <cstdio>
#include <stack>

#define N 1001

using namespace std;

int main()
{
	int order[N];
	int n, c;

	while(scanf("%d", &n), n)
	{
		while(scanf("%d", &order[1]), order[1])
		{
			for(int i = 2; i <= n; ++i)
				scanf("%d", &order[i]);
			
			c = 1;
			stack<int> s;
			for(int i = 1; i <= n; ++i)
			{
				while((s.empty() || s.top() != order[i]) && c <= n)
					s.push(c++);

				if(!s.empty() && s.top() == order[i])
					s.pop();
			}
			
			if(s.empty()) printf("Yes\n");
			else printf("No\n");
		}

		printf("\n");
	}

	return 0;
}

