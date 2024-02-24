// 2905 - Cheap Trips

#include <cstdio>
#include <cstring>
#include <queue>

#define N 10001

int D[N];
float C[N];
float dsc[6] = {1, 0.5, 0.25, 0.25, 0.25, 0.25};

struct trip_t
{
	float c;
	int u, i, d;
	operator const int ()
	{
		return u;
	}
};

bool operator < (const trip_t & a, const trip_t & b)
{
	return a.c > b.c;
}

float dijkstra(const int t)
{
	bool visited[N] = {};

	std::priority_queue<trip_t> q;
	q.push({C[1], 1, 0, D[1]});

	trip_t u;
	while(!q.empty())
	{
		u = q.top(); q.pop();

		if(u == t) break;

		if(!u.i && visited[u]) continue;

		if(!u.i) visited[u] = 1;

		if(u.i < 5 && u.d < 120)
			q.push({u.c + C[u + 1] * dsc[u.i + 1], u + 1, u.i + 1, u.d + D[u + 1]});

		if(!visited[u + 1])
			q.push({u.c + C[u + 1], u + 1, 0, D[u + 1]});
	}

	return u.c;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %f", D + i, C + i);

	printf("%.2f\n", dijkstra(n));

	return 0;
}

