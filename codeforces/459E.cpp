#include <cstdio>
#include <algorithm>
#include <stack>
#include <utility>

#define N 300001
#define M 300001

using namespace std;

struct edge
{
	int u, v, w;
};

bool operator < (const edge & x, const edge & y)
{
	return x.w > y.w;
}

int main()
{
	edge G[M];
	int L[N] = {};

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; ++i)
		scanf("%d %d %d", &G[i].u, &G[i].v, &G[i].w);

	sort(G, G + m);
	
	pair<int, int> p;
	stack<pair<int, int> > s;
	for(int i = 0; i < m; ++i)
	{
		const edge & e = G[i];
		s.push({e.u, max(L[e.u], L[e.v] + 1)});
		
		if(i == m - 1 || e.w != G[i + 1].w)
		{
			while(!s.empty())
			{
				p = s.top(); s.pop();
				L[p.first] = max(L[p.first], p.second);
			}
		}
	}
	
	m = 0;
	for(int i = 1; i <= n; ++i)
		m = max(m, L[i]);

	printf("%d\n", m);

	return 0;
}

