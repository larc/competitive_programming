// 12673 - Football

#include <cstdio>
#include <queue>

#define N 100000 

int main()
{
	int n, g, s, r, p;
	int dif[N], d;

	while(scanf("%d %d", &n, &g) != EOF)
	{
		p = 0; d = 0;
		
		while(n--)
		{
			scanf("%d %d", &s, &r);
			if(s > r) p += 3;
			else if(s == r && g) { p += 3; g--; }
			else if(s == r && !g) p++;
			else if(g) dif[d++] = s - r;
		}

		std::priority_queue<int> q(dif, dif + d);

		while(!q.empty() && g > -q.top())
		{
			p += 3;
			g -= 1 - q.top();
			q.pop();
		}

		while(!q.empty() && g >= -q.top())
		{
			p++; g--;
			q.pop();
		}
		
		printf("%d\n", p);
	}

	return 0;
}

