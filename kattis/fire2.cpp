#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define N 1002


struct pos
{
	int x, y;

	pos operator + (const pos & p) const
	{
		return {x + p.x, y + p.y};
	}
};


char B[N][N] = {};
unsigned int dist[N][N];

int bfs(const std::vector<pos> & sources, const bool stop)
{
	std::queue<pos> q;
	for(auto & p: sources)
	{
		q.push(p);
		dist[p.x][p.y] = 0;
	}

	static const pos neigs[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	while(!q.empty())
	{
		const pos u = q.front();
		q.pop();

		if(!B[u.x][u.y])
		{
			if(stop) return dist[u.x][u.y];
			else continue;
		}

		const unsigned int d = dist[u.x][u.y] + 1;
		for(const auto & n: neigs)
		{
			const pos v = u + n;
			if(B[v.x][v.y] && B[v.x][v.y] != '.')
				continue;

			if(d < dist[v.x][v.y])
			{
				dist[v.x][v.y] = d;
				q.push(v);
			}
		}
	}

	return 0;
}

int main()
{
	int n, w, h;
	std::vector<pos> fire;
	fire.reserve(N);

	pos p;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &w, &h);
		for(int i = 1; i <= h; ++i)
			scanf("%s", B[i] + 1);
		memset(B[h + 1], 0, N);

		fire.clear();
		for(int i = 1; i <= h; ++i)
		for(int j = 1; j <= w; ++j)
		{
			if(B[i][j] == '*') fire.push_back({i, j});
			if(B[i][j] == '@') p = {i, j};
		}

		memset(dist, -1, sizeof(dist));
		B[p.x][p.y] = '.';

		bfs(fire, false);

		h = bfs({p}, true);
		h ? printf("%u\n", h) : printf("IMPOSSIBLE\n");
	}

	return 0;
}

