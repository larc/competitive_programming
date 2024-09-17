// 1424 - Easy Problem from Rujia Liu?

#include <cstdio>
#include <vector>
#include <map>


using namespace std;

int main()
{
	map< int, vector<int> > G;
	unsigned int n, m, k, v;

	while(scanf("%u %u", &n, &m) != EOF)
	{
		for(k = 1; k <= n; ++k)
		{
			scanf("%u", &v);
			G[v].push_back(k);
		}

		while(m--)
		{
			scanf("%u %u", &k, &v);
			k <= G[v].size() ? printf("%d\n", G[v][k - 1]) : printf("0\n");
		}

		G.clear();
	}

	return 0;
}

