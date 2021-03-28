// 11101 - Mall Mania

#include <cstdio>
#include <cstring>
#include <queue>

#define N 2001

struct point
{
	int x, y;
};

int level[N][N];
bool add_valid(const int & i, const int & j, std::queue<point> & q)
{
	if(i < 0 || i >= N) return 0;
	if(j < 0 || j >= N) return 0;
	if(level[i][j] >= 0) return 0;

	q.push({i, j});
	return 1;
}

int main()
{
	int n, i, j;
	bool target[N][N];

	while(scanf("%d", &n) != EOF && n)
	{
		memset(level, -1, sizeof(level));
		memset(target, 0, sizeof(target));

		std::queue<point> q;

		while(n--)
		{
			scanf("%d %d", &i, &j);

			add_valid(i, j, q);
			level[i][j] = 0;
		}

		scanf("%d", &n);
		while(n--)
		{
			scanf("%d %d", &i, &j);
			target[i][j] = 1;
		}

		// BFS solution
		while(!q.empty())
		{
			i = q.front().x;
			j = q.front().y;
			q.pop();

			if(target[i][j]) break;

			n = level[i][j] + 1;
			if(add_valid(i - 1, j, q)) level[i - 1][j] = n;
			if(add_valid(i + 1, j, q)) level[i + 1][j] = n;
			if(add_valid(i, j - 1, q)) level[i][j - 1] = n;
			if(add_valid(i, j + 1, q)) level[i][j + 1] = n;
		}

		printf("%d\n", level[i][j]);
	}

	return 0;
}

