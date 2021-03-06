#include <cstdio>
#include <cstring>
#include <queue>

#define N 999

int c, m, n, s;
int maze[N][N];
bool visited[N][N];
unsigned int W[N][N];

struct node
{
	int x, y;
	unsigned int w;
};

bool operator<(const node & a, const node & b)
{
	return a.w > b.w;
}

void update(std::priority_queue<node> & q, const node & p, const int & x, const int & y)
{
	if(x >= 0 && x < m && y >= 0 && y < n)
	{
		if(!visited[x][y])
		{
			unsigned int d = W[p.x][p.y] + maze[x][y];
			if(d < W[x][y])
			{
				W[x][y] = d;
				q.push({x, y, d});
			}
		}
	}
}

int main()
{
	node p;
	
	scanf("%d", &c);
	while(c--)
	{
		memset(W, 255, sizeof(W)); //inf
		memset(visited, 0, sizeof(visited));

		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &maze[i][j]);
		
		s = m * n;
		W[0][0] = maze[0][0];
		
		std::priority_queue<node> q;
		q.push({0, 0, W[0][0]});
		
		while(s-- && !q.empty())
		{
			p = q.top();
			q.pop();
			
			visited[p.x][p.y] = 1;
		
			update(q, p, p.x - 1, p.y);
			update(q, p, p.x + 1, p.y);
			update(q, p, p.x, p.y - 1);
			update(q, p, p.x, p.y + 1);
		}

		printf("%d\n", W[m - 1][n - 1]);
	}

	return 0;
}

