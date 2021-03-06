// 978 - Lemmings Battle!

#include <cstdio>
#include <queue>

int main()
{
	int winners[100000];
	int n, f, g, b, p, i;

	scanf("%d", &n);
	while(n--)
	{
		std::priority_queue<int> soldiers[2];

		scanf("%d %d %d", &f, &g, &b);

		while(g--)
		{
			scanf("%d", &p);
			soldiers[0].push(p);
		}
		while(b--)
		{
			scanf("%d", &p);
			soldiers[1].push(p);
		}
		
		while(!soldiers[0].empty() && !soldiers[1].empty())
		{
			for(i = 0; i < f && !soldiers[0].empty() && !soldiers[1].empty(); ++i)
			{
				winners[i] = soldiers[0].top() - soldiers[1].top();
				soldiers[0].pop(); soldiers[1].pop();
			}
			
			while(i--)
				if(winners[i] > 0) soldiers[0].push(winners[i]);
				else if(winners[i] < 0) soldiers[1].push(-winners[i]);
		}
		
		if(soldiers[0].empty() && soldiers[1].empty())
			printf("green and blue died\n");
		else
		{
			p = !soldiers[1].empty() && soldiers[0].empty();

			if(p) printf("blue wins\n");
			else printf("green wins\n");

			while(!soldiers[p].empty())
			{
				printf("%d\n", soldiers[p].top());
				soldiers[p].pop();
			}
		}

		if(n) putchar('\n');
	}

	return 0;
}

