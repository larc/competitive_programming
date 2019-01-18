// 12047 - Highest Paid Toll

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define N 10001

using namespace std;

typedef pair<int, int> conn_t;

bool visited[N];
void dijkstra(vector<conn_t> * G, unsigned int * dist, int u)
{
	memset(visited, 0, sizeof(visited));
	dist[u] = 0;

	priority_queue<conn_t, vector<conn_t>, greater<conn_t> > q;
	q.push({0, u});
	
	while(!q.empty())
	{
		u = q.top().second; q.pop();
		visited[u] = 1;

		for(conn_t & c: G[u])
		{
			int & v = c.second;
			if(!visited[v] && dist[v] > dist[u] + c.first)
			{
				dist[v] = dist[u] + c.first;
				q.push({dist[v], v});
			}
		}
	}
}

int main()
{
	vector<conn_t> sG[N];
	vector<conn_t> tG[N];
	unsigned int sd[N], td[N];

	int n_cases, n, m, s, t, p, u, v, w;
	
	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			sG[u].push_back({w, v});
			tG[v].push_back({w, u});
		}
		
		memset(sd, -1, sizeof(sd));
		memset(td, -1, sizeof(td));
		dijkstra(sG, sd, s);
		dijkstra(tG, td, t);

		t = -1;
		for(u = 1; u <= n; u++)
		for(conn_t & c: sG[u])
		{
			v = c.second;
			w = sd[u] + td[v] + c.first;
			if(sd[u] != -1 && td[v] != -1 && w <= p && c.first > t) t = c.first;
		}
		
		printf("%d\n", t);

		for(u = 1; u <= n; u++)
		{
			sG[u].clear();
			tG[u].clear();
		}
	}

	return 0;
}

