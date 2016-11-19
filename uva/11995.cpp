#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n, o, x, c, sc, qc, pc;
	while(scanf("%d", &n) != EOF)
	{
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;
		c = sc = qc = pc = 0;
		while(n--)
		{
			scanf("%d %d", &o, &x);
			if(o == 1)
			{
				s.push(x);
				q.push(x);
				p.push(x);
			}
			else
			{
				c++;
				if(!s.empty() && s.top() == x)
				{
					sc++;
					s.pop();
				}
				if(!q.empty() && q.front() == x)
				{
					qc++;
					q.pop();
				}
				if(!p.empty() && p.top() == x)
				{
					pc++;
					p.pop();
				}
			}
		}
		if(c != sc && c != qc && c != pc) printf("impossible\n");
		else if(c == sc && c != qc && c != pc) printf("stack\n");
		else if(c != sc && c == qc && c != pc) printf("queue\n");
		else if(c != sc && c != qc && c == pc) printf("priority queue\n");
		else printf("not sure\n");

	}
	return 0;
}
