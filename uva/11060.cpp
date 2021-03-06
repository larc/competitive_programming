// 11060 - Beverages

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>

#define N 100

int G[N][N];
int in_deg[N];
int out_deg[N];

int main()
{
	std::map<std::string, int> idx;
	char beverages[N][52], bu[52], bv[52];
	int n, m, u, v, n_case = 1;

	std::priority_queue<int> q;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", beverages[i]);
			idx[beverages[i]] = i;
		}
		
		memset(in_deg, 0, sizeof(in_deg));
		memset(out_deg, 0, sizeof(out_deg));

		scanf("%d", &m);
		while(m--)
		{
			scanf("%s %s", bu, bv);
			u = idx[bu];
			v = idx[bv];

			G[u][out_deg[u]++] = v;
			in_deg[v]++;
		}

		for(int i = 0; i < n; ++i)
			if(!in_deg[i]) q.push(-i);
	
		printf("Case #%d: Dilbert should drink beverages in this order:", n_case++);
		while(!q.empty())
		{
			u = -q.top(); q.pop();
			printf(" %s", beverages[u]);

			for(int i = 0; i < out_deg[u]; ++i)
			{
				v = G[u][i];
				in_deg[v]--;
				if(!in_deg[v]) q.push(-v);
			}
		}

		printf(".\n\n");

		idx.clear();
	}

	return 0;
}

