#include <cstdio>
#include <cstring>
#include <queue>
#include <array>

#define N 1002

char maze[N][N] = {};
int dist[N][N] = {};

using point = std::array<int, 2>;

char & pmaze(const point & p)
{
	return maze[p[0]][p[1]];
}

int & pdist(const point & p)
{
	return dist[p[0]][p[1]];
}

point operator + (const point & a, const point & b)
{
	return {a[0] + b[0], a[1] + b[1]};
}

const point dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool check(const point & a, const int rows, const int cols)
{
	return pmaze(a) == 'J' && (a[0] == rows || a[1] == cols || a[0] == 1 || a[1] == 1);
}

int bfs(const int rows, const int cols)
{
	std::queue<point> q;

	point a;
	for(int i = 1; i <= rows; ++i)
	for(int j = 1; j <= cols; ++j)
	{
		if(maze[i][j] == 'F')
		{
			q.push({i, j});
			dist[i][j] = 0;
		}

		if(maze[i][j] == 'J')
		{
			a = {i, j};
			dist[i][j] = 0;
		}
	}

	if(check(a, rows, cols))
		return pdist(a) + 1;

	q.push(a);
	while(!q.empty())
	{
		a = q.front(); q.pop();

		const char ma = pmaze(a);

		for(const point & d: dirs)
		{
			const point & b = a + d;
			char & mb = pmaze(b);

			if(mb != '.') continue;

			mb = ma;
			pdist(b) = pdist(a) + 1;
			if(check(b, rows, cols))
				return pdist(b) + 1;

			q.push(b);
		}
	}

	return -1;
}

int main()
{
	int rows, cols, time;

	scanf("%d %d", &rows, &cols);
	for(int i = 1; i <= rows; ++i)
		scanf("%s", maze[i] + 1);

	memset(maze[rows + 1], 0, N);

	time = bfs(rows, cols);
	time == -1 ? printf("IMPOSSIBLE\n") : printf("%d\n", time);

	return 0;
}

