#include <cstdio>
#include <cstring>


char sudoku[9][10] = {};
bool rows[9][9] = {};
bool cols[9][9] = {};
bool blocks[3][3][9] = {};

bool check()
{
	memset(rows, 0, sizeof(rows));
	memset(cols, 0, sizeof(cols));
	memset(blocks, 0, sizeof(blocks));

	for(int i = 0; i < 9; ++i)
	for(int j = 0; j < 9; ++j)
	{
		if(sudoku[i][j] == '.')
			continue;

		int p = sudoku[i][j] - '1';
		if(rows[i][p]) return false;
		if(cols[j][p]) return false;
		if(blocks[i/3][j/3][p]) return false;
		rows[i][p] = true;
		cols[j][p] = true;
		blocks[i/3][j/3][p] = true;
	}
	return true;
}

int main()
{
	int n_cases;
	const char * ans[2] = {"NO", "SI"};

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		for(int i = 0; i < 9; ++i)
			scanf("%s", sudoku[i]);
		printf("%s\n", ans[check()]);
	}

	return 0;
}
