#include <cstdio>
#include <vector>
#include <queue>

#define N 1000

int comp[N << 1];

void init(const int & n)
{
	for(int i = 0; i < n; ++i)
		comp[i] = i;
}

int find(const int & x)
{
	return comp[x] == x ? x : comp[x] = find(comp[x]);
}

void join(int x, int y)
{
	comp[find(y)] = find(x);
}

int main()
{
	std::vector<int> G[N << 1];
	int in_degree[N << 1] = {};
	int value[N << 1] = {};

	char str[N][N + 1];
	int n, m;

	scanf("%d %d", &n, &m);

	init(n + m);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s", str[i]);
		for(int j = 0; j < m; ++j)
			if(str[i][j] == '=')
				join(i, j + n);
	}

	for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j)
		if(str[i][j] == '<')
		{
			in_degree[find(j + n)]++;
			G[find(i)].push_back(find(j + n));
		}
		else if(str[i][j] == '>')
		{
			in_degree[find(i)]++;
			G[find(j + n)].push_back(find(i));
		}


	m += n;

	int k = 0;
	std::queue<int> q;

	for(int i = 0; i < m; ++i)
		if(comp[i] == i)
		{
			k++;
			if(!in_degree[i])
			{
				value[i] = 1;
				q.push(i);
			}
		}

	while(!q.empty())
	{
		const int & u = q.front();
		for(const int & v: G[u])
		{
			in_degree[v]--;
			value[v] = std::max(value[u] + 1, value[v]);

			if(!in_degree[v])
				q.push(v);
		}

		q.pop(); k--;
	}

	if(k)
	{
		printf("No\n");
		return 0;
	}

	printf("Yes\n");

	for(int i = 0; i < n; ++i)
		printf("%d ", value[find(i)]);
	putchar('\n');

	for(int i = n; i < m; ++i)
		printf("%d ", value[find(i)]);
	putchar('\n');

	return 0;
}

