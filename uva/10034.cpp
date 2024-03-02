// 10034 - Freckles

#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

#define N 100

struct point
{
	float x = 0;
	float y = 0;

	point(const float ix = 0, const float iy = 0) : x(ix), y(iy) {}

	point operator - (const point & p)
	{
		return {x - p.x, y - p.y};
	}
};

float length(const point & p)
{
	return sqrt(p.x * p.x + p.y * p.y);
}

point points[N];
bool visited[N];

float prim(const int n)
{
	memset(visited, 0, sizeof(visited));

	std::priority_queue<std::pair<float, int> > q;
	q.push({0, 0});

	int mst = 0;
	float sum = 0;
	while(!q.empty())
	{
		const float w = -q.top().first;
		const int u = q.top().second;
		q.pop();

		if(visited[u]) continue;

		visited[u] = true;
		sum += w;

		if(++mst == n) break;

		for(int v = 0; v < n; ++v)
			if(!visited[v])
				q.push({-length(points[u] - points[v]), v});
	}

	return sum;
}

int main()
{
	int n_cases, n;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			point & p = points[i];
			scanf("%f %f", &p.x, &p.y);
		}

		printf("%.2f\n", prim(n));
		if(n_cases) putchar('\n');
	}

	return 0;
}

