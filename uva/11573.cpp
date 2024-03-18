// 11573 - Ocean Currents

#include <cstdio>
#include <cstring>
#include <deque>

#define N 1002

int rows, cols;
char G[N][N] = {};
unsigned dist[N * N] = {};

struct point
{
	int x = 0;
	int y = 0;

	point() = default;

	point(const int i)
	{
		x = i / cols + 1;
		y = i % cols + 1;
	}

	point(const int ax, const int ay): x(ax), y(ay) {};

	operator int () const
	{
		return (x - 1) * cols + y - 1;
	}

	point operator + (const point & p)
	{
		return {x + p.x, y + p.y};
	}
};

const point dir[8] = { 	{-1, 0},
						{-1, 1},
						{0, 1},
						{1, 1},
						{1, 0},
						{1, -1},
						{0, -1},
						{-1, -1}
						};

inline char & gflow(const point & p)
{
	return G[p.x][p.y];
}

unsigned bfs(point a, const point & b)
{
	memset(dist, -1, sizeof(dist));

	std::deque<int> q;
	q.push_back(a);
	dist[a] = 0;

	while(!q.empty())
	{
		a = q.front();
		q.pop_front();

		const char flow = gflow(a);
		for(int i = 0; i < 8; ++i)
		{
			const point & c = a + dir[i];
			if(!gflow(c)) continue;

			const bool current = i != flow - '0';
			if(dist[c] > dist[a] + current)
			{
				dist[c] = dist[a] + current;
				current ? q.push_back(c) : q.push_front(c);
			}
		}
	}

	return dist[b];
}

int main()
{
	scanf("%d %d", &rows, &cols);
	for(int i = 1; i <= rows; ++i)
		scanf("%s", &G[i][1]);

	int n;
	point p, q;

	scanf("%d", &n);
	do
	{
		scanf("%d %d %d %d", &p.x, &p.y, &q.x, &q.y);
		printf("%u\n", bfs(p, q));
	}
	while(--n);

	return 0;
}

