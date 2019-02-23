#include <cstdio>
#include <vector>

#define N 150001

std::vector<int> T[N];

void dfs(const int & u)
{
	printf("%d ", u);

	for(const int & v: T[u])
		dfs(v);
}

int comp[N];

void init(const int & n)
{
	for(int i = 1; i <= n; i++)
		comp[i] = i;
}

int find(const int & x)
{
	return comp[x] == x ? x : comp[x] = find(comp[x]);
}

void join(int x, int y)
{
	x = find(x);
	y = find(y);

	comp[y] = x;
	T[x].push_back(y);
}

int main()
{
	int n, a, b;

	scanf("%d", &n);

	init(n);
	for(int i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		join(a, b);
	}
	
	for(a = 1; a <= n; a++)
		if(comp[a] == a) break;

	dfs(a); putchar('\n');

	return 0;
}

