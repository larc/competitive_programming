#include <cstdio>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map <int, int> visited;

void bfs(int start, map <int, vector<int> > & graph)
{
	queue<int> s;
	s.push(start);
	visited[start] = 0;
	int top, size, n, i;
	while(!s.empty())
	{
		top = s.front();
		s.pop();
		size = graph[top].size();
		for(i = 0; i < size; ++i)
		{
			n = graph[top][i];
			if(!visited.count(n))
			{
				visited[n] = visited[top] + 1;
				s.push(n);
			}
		}
	 }
}

int main()
{
	int nods, a, b, cases = 1;
	int ttl, start, result;

	while(scanf("%d", &nods) && nods)
	{
		map <int,vector<int> > graph;
		while(nods--)
		{
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		while(scanf("%d %d", &start, &ttl) && (start || ttl))
		{
			visited.clear();
			bfs(start, graph);
			result = 0;

			for(auto itr: visited)
				if( itr.second > ttl) ++result;

			result += graph.size() - visited.size();

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cases, result, start, ttl);
			cases++;
		}
	}

	return 0;
}
