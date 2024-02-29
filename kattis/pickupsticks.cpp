#include <cstdio>
#include <queue>

#define N 1000001

std::vector<int> G[N];
std::vector<int> in_degree;
std::vector<int> S;

bool top_sort(const unsigned int n)
{
	S.clear();
	for(unsigned int u = 1; u <= n; ++u)
		if(!in_degree[u])
			S.push_back(u);

	for(unsigned int i = 0; i < S.size(); ++i)
	{
		const int u = S[i];
		for(const int v: G[u])
			if(--in_degree[v] == 0)
				S.push_back(v);
	}

	return S.size() == n;
}

int main()
{
	S.reserve(N);
	in_degree.reserve(N);

	unsigned int n, m, u, v;
	while(scanf("%u %u", &n, &m) != EOF)
	{
		in_degree.assign(n + 1, 0);
		for(unsigned int u = 1; u <= n; ++u)
			G[u].clear();

		while(m--)
		{
			scanf("%u %u", &u, &v);
			G[u].push_back(v);
			++in_degree[v];
		}

		if(!top_sort(n))
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		for(const int u: S)
			printf("%d\n", u);
	}

	return 0;
}

