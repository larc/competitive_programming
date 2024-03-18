// 429 - Word Transformation

#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>

#define N 201

using namespace std;

int G[N][N];
int size[N];
int level[N];

int bfs(int u, const int v)
{
	memset(level, -1, sizeof(level));

	level[u] = 0;
	queue<int> q;
	q.push(u);

	while(!q.empty())
	{
		u = q.front();
		q.pop();

		if(u == v) return level[v];
		for(int i = 0; i < size[u]; ++i)
		{
			int & w = G[u][i];
			if(level[w] < 0)
			{
				level[w] = level[u] + 1;
				q.push(w);
			}
		}
	}

	return -1;
}

bool compare(const string & wa, const string & wb)
{
	if(wa.size() != wb.size()) return 0;

	int c = 0;
	for(unsigned int i = 0; i < wa.size(); ++i)
		if(wa[i] != wb[i]) c++;

	return c == 1;
}

int main()
{
	char line[23];
	char wa[11], wb[11];

	string words[N];
	int n, n_cases;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		memset(size, 0, sizeof(size));
		map<string, int> msi;

		n = 0;
		while(scanf("%s", wa), wa[0] != '*')
		{
			n++;
			msi[wa] = n;
			words[n] = wa;

			for(int i = 1; i < n; ++i)
				if(compare(words[i], words[n]))
				{
					G[i][size[i]++] = n;
					G[n][size[n]++] = i;
				}
		}

		fgets(line, sizeof(line), stdin);
		while(fgets(line, sizeof(line), stdin) && line[0] != '\n')
		{
			sscanf(line, "%s %s", wa, wb);
			printf("%s %s %d\n", wa, wb, bfs(msi[wa], msi[wb]));
		}

		if(n_cases) putchar('\n');
	}

	return 0;
}

