// 11561 - Getting Gold

#include <cstdio>
#include <algorithm>

char map[51][51];

int dfs(const int & x, const int & y)
{
	char c = map[x][y];
	map[x][y] = 'X';

	if( map[x - 1][y] == 'T' ||
		map[x + 1][y] == 'T' ||
		map[x][y - 1] == 'T' ||
		map[x][y + 1] == 'T'
		)
		return c == 'G';

	int count = 0;
	auto check_dfs = [&count](const int & i, const int & j)
	{
		const char & c = map[i][j];
		if(c == '.' || c == 'G')
			count += dfs(i, j);
	};

	check_dfs(x - 1, y);
	check_dfs(x + 1, y);
	check_dfs(x, y - 1);
	check_dfs(x, y + 1);

	return count + (c == 'G');
}

int main()
{
	int w, h;
	while(scanf("%d %d", &w, &h) != EOF)
	{
		for(int i = 0; i < h; ++i)
			scanf("%s", map[i]);

		for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
			if(map[i][j] == 'P')
			{
				printf("%d\n", dfs(i, j));
				i = h;
				j = w;
			}
	}

	return 0;
}

