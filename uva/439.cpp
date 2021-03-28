#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int square[8][8];

struct point_t
{
	int x, y;
	bool operator == (const point_t & p)
	{
		return x == p.x && y == p.y;
	}
	bool valid()
	{
		return x >= 0 && x < 8 && y >= 0 && y < 8;
	}
};

int moves(char * x, char * y)
{
	memset(square, 0, sizeof(square));

	point_t a, b;
	a.x = x[0] - 'a'; a.y = x[1] - '1';
	b.x = y[0] - 'a'; b.y = y[1] - '1';

	queue<point_t> q;
	q.push(a);

	auto visit = [&](const int & i, const int & j)
	{
		point_t p = a;
		p.x += i;
		p.y += j;

		if(p.valid() && !square[p.x][p.y])
		{
			square[p.x][p.y] = square[a.x][a.y] + 1;
			q.push(p);
		}
	};

	while(!q.empty())
	{
		a = q.front();
		q.pop();

		if(a == b) return square[a.x][a.y];

		visit(-2, -1);
		visit(-2, 1);
		visit(-1, -2);
		visit(-1, 2);
		visit(2, -1);
		visit(2, 1);
		visit(1, -2);
		visit(1, 2);
	}

	return 0;
}

int main()
{
	char x[3], y[3];
	while(scanf("%s %s", x, y) != EOF)
		printf("To get from %2s to %2s takes %d knight moves.\n", x, y, moves(x, y));
	return 0;
}

