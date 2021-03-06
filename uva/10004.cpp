#include <cstdio>
#include <cstring>
#include <queue>

#define N 200

int g[N][N]; // adjacent list
int size[N]; // number of neighbors 
int color[N]; // -1: unvisited, 0 o 1 color

int main()
{
	int n, e, a, b;

	while(scanf("%d", &n) && n)
	{
		memset(size, 0, sizeof(size));
		memset(color, -1, sizeof(color));

		scanf("%d", &e);
		while(e--)
		{
			scanf("%d %d", &a, &b);
			g[a][size[a]++] = b;
			g[b][size[b]++] = a;
		}
		
		std::queue<int> q;
		q.push(0);
		color[0] = 0;

		bool bicoloreable = true;
		while(!q.empty() && bicoloreable)
		{
			a = q.front();
			q.pop();
			
			for(b = 0; b < size[a]; ++b)
			{
				if(color[g[a][b]] == -1)
				{
					color[g[a][b]] = 1 - color[a];
					q.push(g[a][b]);
				}
				else if(color[g[a][b]] != 1 - color[a])
				{
					bicoloreable = false;
					break;
				}
			}
		}

		if(bicoloreable) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}

	return 0;
}

