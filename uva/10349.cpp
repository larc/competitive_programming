// 10349 - Antenna Placement

#include <cstdio>
#include <cstring>

#define H 42
#define W 12

char A[H][W];
bool visited[H][W];

struct match_t
{
	int i, j;

	operator bool()
	{
		return i != -1;
	}
}
match[H][W];

const int N [4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

bool aug(const int & i, const int & j)
{
	if(visited[i][j]) return 0;
	visited[i][j] = 1;

	for(int k = 0; k < 4; ++k)
	{
		const int x = i + N[k][0];
		const int y = j + N[k][1];

		if(A[x][y] == '*' && (!match[x][y] || aug(match[x][y].i, match[x][y].j)))
		{
			match[i][j] = {x, y};
			match[x][y] = {i, j};

			return 1;
		}
	}

	return 0;
}

int main()
{
	memset(A, 0, sizeof(A));

	int n, h, w, mcbm;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &h, &w);
		for(int i = 1; i <= h; ++i)
			scanf("%s", A[i] + 1);

		memset(A[h + 1], 0, W);

		mcbm = 0;
		memset(match, -1, sizeof(match));

		for(int i = 1; i <= h; ++i)
		for(int j = 1; j <= w; ++j)
		{
			memset(visited, 0, sizeof(visited));
			if(((i + j) & 1) && A[i][j] == '*' && aug(i, j))
				mcbm++;
		}

		for(int i = 1; i <= h; ++i)
		for(int j = 1; j <= w; ++j)
			if(A[i][j] == '*' && !match[i][j])
				mcbm++;

		printf("%d\n", mcbm);
	}

	return 0;
}

