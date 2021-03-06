#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map< int, vector<int> > G;
	int n, m, k, v;

	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(k = 1; k <= n; ++k)
		{
			scanf("%d", &v);
			G[v].push_back(k);
		}

		while(m--)
		{
			scanf("%d %d", &k, &v);
			if(k <= G[v].size()) printf("%d\n", G[v][k - 1]);
			else printf("0\n");
		}
		
		G.clear();
	}
		
	return 0;
}

