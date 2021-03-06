#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define S 20000

using namespace std;

struct cable_t
{
	unsigned int c; // computer
	unsigned int w; // latency
};

bool operator<(const cable_t & a, const cable_t & b)
{
	return a.w > b.w;
}

int main()
{
	unsigned int N, n, m, s, t, a, b, w;
	unsigned int d[S]; // distances
	bool visited[S]; // distances
	vector<cable_t> W[S];
	
	scanf("%u", &N);
	for(int c = 1; c <= N; ++c)
	{
		scanf("%u %u %u %u", &n, &m, &s, &t);

		for(int i = 0; i < n; ++i)
			W[i].clear();

		while(m--)
		{
			scanf("%u %u %u", &a, &b, &w);
			W[a].push_back({b, w});
			W[b].push_back({a, w});
		}

		// dijkstra
		memset(visited, 0, sizeof(visited));
		memset(d, 255, sizeof(d)); //inf
		d[s] = 0;

		priority_queue<cable_t> q;
		q.push({s, d[s]});

		while(!q.empty())
		{
			s = q.top().c;
			q.pop();
			
			visited[s] = 1;
			if(s == t) break;
			
			for(cable_t & cable: W[s])
			{
				w = d[s] + cable.w;
				if(w < d[cable.c])
				{
					d[cable.c] = w;
					q.push({cable.c, w});
				}
			}
		}
		
		if(visited[t]) printf("Case #%u: %u\n", c, d[t]);
		else printf("Case #%u: unreachable\n", c);
	}

	return 0;
}

