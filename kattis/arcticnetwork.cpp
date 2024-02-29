#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

#define N 500

struct coor_t
{
	float x, y;

	coor_t operator - (coor_t & c) const
	{
		return {x - c.x, y - c.y};
	}
};

float norm(const coor_t & c)
{
	return c.x * c.x + c.y * c.y;
}

coor_t C[N];	// complete graph
float D[N][N];

struct edge_t
{
	int a, b;
};

bool operator < (const edge_t & u, const edge_t & v)
{
	return D[u.a][u.b] > D[v.a][v.b];
}

int S[N];

const int find_s(const int x)
{
	if(S[x] == x) return x;
	return S[x] = find_s(S[x]);
}

bool union_s(int x, int y)
{
	x = find_s(x);
	y = find_s(y);

	if(x == y) return 0;

	S[y] = x;
	return 1;
}

float kruskal(const int p, std::priority_queue<edge_t> & q, int s)
{
	edge_t edge;
	float d = 0;
	while(!q.empty() && s)
	{
		edge = q.top();
		q.pop();
		if(union_s(edge.a, edge.b))
		{
			s--;
			d = D[edge.a][edge.b];
		}
	}

	return sqrt(d);
}

int main()
{
	int n, p, s;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &s, &p);
		for(int i = 0; i < p; ++i)
			scanf("%f %f", &C[i].x, &C[i].y);

		//e = 0;
		std::priority_queue<edge_t> q;
		for(int i = 0; i < p; ++i)
		for(int j = i + 1; j < p; ++j)
		{
			D[i][j] = D[j][i] = norm(C[i] - C[j]);
			q.push({i, j});
		}

		for(int i = 0; i < p; ++i) // initialization union find
			S[i] = i;

		//printf("%.2f\n", kruskal(p, e, p - s));
		printf("%.2f\n", kruskal(p, q, p - s));
	}

	return 0;
}

