#include <cstdio>
#include <cstring>
#include <queue>

#define N 100

int r, c;
int heights[N][N];
int lpath[N][N];	// length max path to lpath[i][j]

struct point_t
{
	int x;
	int y;
};

bool is_connected(const point_t & p, const point_t & q)
{
	if(q.x < 0 || q.x >= r || q.y < 0 || q.y >= c)
		return 0;
	if(heights[p.x][p.y] > heights[q.x][q.y])
		return 1;
	return 0;
}

int relax(const point_t & p, const point_t & q);
int dfs(const point_t & p)	// C++11 0.000s
{
	int m = 0, d;
	d = relax(p, {p.x - 1, p.y});
	if(d > m) m = d;
	d = relax(p, {p.x + 1, p.y});
	if(d > m) m = d;
	d = relax(p, {p.x, p.y - 1});
	if(d > m) m = d;
	d = relax(p, {p.x, p.y + 1});
	if(d > m) m = d;

	if(!m) return lpath[p.x][p.y];
	return m;
}

int relax(const point_t & p, const point_t & q)
{
	if(is_connected(p, q))
	{
		if(lpath[q.x][q.y] <= lpath[p.x][p.y] + 1)
		{
			lpath[q.x][q.y] = lpath[p.x][p.y] + 1;
			return dfs(q);
		}
	}

	return 0;
}

void relax(const point_t & p, const point_t & q, std::queue<point_t> & qq);
void bfs(point_t p) // C++11 0.020s
{
	std::queue<point_t> q;
	q.push(p);

	while(!q.empty())
	{
		p = q.front();
		q.pop();

		relax(p, {p.x - 1, p.y}, q);
		relax(p, {p.x + 1, p.y}, q);
		relax(p, {p.x, p.y - 1}, q);
		relax(p, {p.x, p.y + 1}, q);
	}
}

void relax(const point_t & p, const point_t & q, std::queue<point_t> & qq)
{
	if(is_connected(p, q))
	{
		if(lpath[q.x][q.y] <= lpath[p.x][p.y] + 1)
		{
			lpath[q.x][q.y] = lpath[p.x][p.y] + 1;
			qq.push(q);
		}
	}
}

int main()
{
	int n, x, y;
	int length, l;
	char name[32];
	int p;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%s %d %d", name, &r, &c);

		for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
		{
			scanf("%d", &heights[i][j]);
			lpath[i][j] = 1;
		}

		length = 0;
		for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
		{
			l = dfs({i, j});
			if(l > length) length = l;
		}
		printf("%s: %d\n", name, length);
	}

	return 0;
}

