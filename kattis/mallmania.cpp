#include <cstdio>
#include <cstring>
#include <queue>

#define N 2001

struct point
{
	int x, y;
};

int level[N][N];
std::queue<point> q;

void add_valid(const int & i, const int & j, const int & n)
{
	if(i < 0 || i >= N) return;
	if(j < 0 || j >= N) return;
	if(level[i][j] >= 0) return;

	q.push({i, j});
	level[i][j] = n;
}

int main()
{
	int n, i, j;
	bool target[N][N];

	while(scanf("%d", &n) != EOF && n)
	{
		memset(level, -1, sizeof(level));
		memset(target, 0, sizeof(target));

		while(n--)
		{
			scanf("%d %d", &i, &j);
			add_valid(i, j, 0);
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
			add_valid(i - 1, j, n);
			add_valid(i + 1, j, n);
			add_valid(i, j - 1, n);
			add_valid(i, j + 1, n);
		}

		printf("%d\n", level[i][j]);

		while(!q.empty()) q.pop();
	}

	return 0;
}

