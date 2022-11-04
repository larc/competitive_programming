// 200 - Rare Order

#include <cstdio>
#include <cstring>
#include <string>

bool G[27][27] = {};
bool visited[27] = {};
bool input[27] = {};

std::string top_sort(const int & i)
{
	std::string tp = "";

	visited[i] = true;
	for(int j = 0; j < 27; ++j)
		if(G[i][j] && !visited[j])
			tp = top_sort(j) + tp;

	return char('A' + i) + tp;
}

int main()
{
	char a[21], b[21];

	scanf("%s", a);
	while(scanf("%s", b), *b != '#')
	{
		for(int k = 0; a[k] && b[k]; ++k)
			if(a[k] != b[k])
			{
				input[a[k] - 'A'] = true;
				input[b[k] - 'A'] = true;
				G[a[k] - 'A'][b[k] - 'A'] = true;
				break;
			}

		memcpy(a, b, sizeof(b));
	}

	std::string tp = "";
	for(int i = 0; i < 27; ++i)
		if(input[i] && !visited[i])
			tp = top_sort(i) + tp;

	printf("%s\n", tp.c_str());

	return 0;
}

