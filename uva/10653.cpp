// 10653 - Bombs! NO they are Mines!!

#include <cstdio>
#include <cstring>
#include <queue>

#define N 1000

struct point
{
	int x, y;
};

point moves[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int grid[N][N];
int R, C;

bool valid(const point & p)
{
	if(p.x < 0 || p.x >= R) return 0;
	if(p.y < 0 || p.y >= C) return 0;
	return 1;
}

int bfs(point s, const point & d)
{
	std::queue<point> q;
	q.push(s);

	grid[s.x][s.y] = 0;

	point p;
	while(!q.empty())
	{
		s = q.front();
		q.pop();

		if(s.x == d.x && s.y == d.y) break;

		for(int i = 0; i < 4; ++i)
		{
			p.x = s.x + moves[i].x;
			p.y = s.y + moves[i].y;
			if(valid(p) && grid[p.x][p.y] < 0)
			{
				grid[p.x][p.y] = grid[s.x][s.y] + 1;
				q.push(p);
			}
		}
	}

	return grid[d.x][d.y];
}

int main()
{
	int n, r, m, c;
	point s, d;

	while(scanf("%d %d", &R, &C), R && C)
	{
		memset(grid, -1, sizeof(grid));

		scanf("%d", &n);
		while(n--)
		{
			scanf("%d %d", &r, &m);
			while(m--)
			{
				scanf("%d", &c);
				grid[r][c] = N;
			}
		}

		scanf("%d %d", &s.x, &s.y);
		scanf("%d %d", &d.x, &d.y);
		printf("%d\n", bfs(s, d));
	}

	return 0;
}

