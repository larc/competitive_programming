// 314 - Robot

#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define N 51

bool grid[N][N];
int m, n;

struct point
{
	int x, y;

	bool operator == (const point & p)
	{
		return x == p.x && y == p.y;
	}
};

int _time[N][N][N];
int & time(const point & p, const int & d)
{
	return _time[p.x][p.y][d];
}

bool valid(const point & p)
{
	if(p.x <= 0 || p.x >= m) return 0;
	if(p.y <= 0 || p.y >= n) return 0;
	
	if(p.x && grid[p.x - 1][p.y]) return 0;
	if(p.y && grid[p.x][p.y - 1]) return 0;
	if(p.x && p.y && grid[p.x - 1][p.y - 1]) return 0;
	if(grid[p.x][p.y]) return 0;

	return 1;
}

bool go(const char & dir, const int & s, const point & p, point & q)
{
	q = p;
	if(dir & 1) q.y += dir == 1 ? s : -s;
	else q.x += dir ? s : -s;
	
	return valid(q);
}

int bfs(point p, char dir, const point & q)
{
	memset(_time, -1, sizeof(_time));

	std::queue<std::pair<point, char> > queue;
	queue.push({p, dir});
	time(p, dir) = 0;

	char d;
	point r;
	while(!queue.empty())
	{
		p = queue.front().first;
		dir = queue.front().second;
		queue.pop();
		
		if(p == q) return time(q, dir);
		
		if(time(p, d = (dir + 1) % 4) < 0) // turn right
		{
			time(p, d) = time(p, dir) + 1;
			queue.push({p, d});
		}

		if(time(p, d = (dir + 3) % 4) < 0) // turn left
		{
			time(p, d) = time(p, dir) + 1;
			queue.push({p, d});
		}

		for(int s = 1; s <= 3; ++s) // go {1, 2, 3}
		{
			if(!go(dir, s, p, r)) break;
			if(time(r, dir) < 0)
			{
				time(r, dir) = time(p, dir) + 1;
				queue.push({r, dir});
			}
		}
	}
	
	return -1;
}

int main()
{
	point p, q;
	int b;
	char orientation[6], dir;

	while(scanf("%d %d", &m, &n), n || m)
	{
		memset(grid, 0, sizeof(grid));
		for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
		{
			scanf("%d", &b);
			if(b) grid[i][j] = 1;
		}
		
		scanf("%d %d %d %d %s", &p.x, &p.y, &q.x, &q.y, orientation);

		if(orientation[0] == 'n') dir = 0;
		if(orientation[0] == 'e') dir = 1;
		if(orientation[0] == 's') dir = 2;
		if(orientation[0] == 'w') dir = 3;

		printf("%d\n", bfs(p, dir, q));
	}

	return 0;
}

