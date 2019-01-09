// 11492 - Babel

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define S 64
#define N 2000

using namespace std;

int main()
{
	vector<unsigned> G[N];
	bool visited[N];
	unsigned dist[N];
	bool dest[N];
	
	char cu[S], cv[S], w[S], s[S], d[S];
	string words[N];

	unsigned n, u, v;

	map<string, vector<unsigned> > languages;
	while(scanf("%d", &n) && n)
	{
		scanf("%s %s", s, d);

		for(unsigned i = 0; i < n; i++)
		{
			scanf("%s %s %s", cu, cv, w);
			languages[cu].push_back(i);
			languages[cv].push_back(i);
			words[i] = w;
		}

		for(auto & psv: languages)
		{
			vector<unsigned> & v = psv.second;
			for(unsigned i = 0; i < v.size(); i++)
			for(unsigned j = i + 1; j < v.size(); j++)
				if(words[v[i]][0] != words[v[j]][0])
				{
					G[v[i]].push_back(v[j]);
					G[v[j]].push_back(v[i]);
				}
		}

		memset(visited, 0, sizeof(visited));
		memset(dest, 0, sizeof(dest));
		memset(dist, -1, sizeof(dist));

		priority_queue< pair<unsigned, unsigned>,
						vector<pair<unsigned, unsigned> >,
						greater<pair<unsigned, unsigned> > > q;

		for(unsigned & u: languages[s])
		{
			dist[u] = words[u].size();
			q.push({dist[u], u});
		}
		
		for(unsigned & u: languages[d])
			dest[u] = 1;

		while(!q.empty())
		{
			u = q.top().second; q.pop();
			visited[u] = 1;

			if(dest[u]) break;

			for(unsigned & v: G[u])
				if(!visited[v] && dist[v] > dist[u] + words[v].size())
				{
					dist[v] = dist[u] + words[v].size();
					q.push({dist[v], v});
				}
		}
	
		if(dest[u] && dist[u] != -1) printf("%u\n", dist[u]);
		else printf("impossivel\n");

		languages.clear();
		for(unsigned i = 0; i < n; i++)
			G[i].clear();
	}

	return 0;
}

