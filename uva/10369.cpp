#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

#define N 500

struct coor_t
{
	float x = 0;
	float y = 0;

	float norm(coor_t c)
	{
		c.x -= x;
		c.y -= y;
		return c.x * c.x + c.y * c.y;
	}
};

coor_t C[N];	// complete graph
float D[N][N];

bool visited[N];	// prim visited vertices
float dt[N]; 	// edge values minimum spanning tree

struct edge_t
{
	int a, b;
};

bool operator<(const edge_t & u, const edge_t & v)
{
	return D[u.a][u.b] > D[v.a][v.b];
}

void prim(const int p)
{
	memset(visited, 0, sizeof(visited));

	int i, j;
	std::priority_queue<edge_t> q;

	i = 0;
	visited[i] = 1;
	for(j = 1; j < p; ++j)
		q.push({i, j});

	int d = 0;
	while(!q.empty())
	{
		i = q.top().a;
		j = q.top().b;
		q.pop();

		if(!visited[j])
		{
			visited[j] = 1;

			dt[d++] = D[i][j];

			for(i = 0; i < p; ++i)
				if(i != j && !visited[i])
					q.push({j, i});
		}
	}
}

int main_prim() // 0.090 c++11
{
	int n, p, s;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &s, &p);
		for(int i = 0; i < p; ++i)
			scanf("%f %f", &C[i].x, &C[i].y);

		for(int i = 0; i < p; ++i)
		for(int j = i + 1; j < p; ++j)
			D[i][j] = D[j][i] = C[i].norm(C[j]);

		prim(p);
		std::sort(dt, dt + p - 1);
		printf("%.2f\n", sqrt(dt[p - s - 1]));
	}

	return 0;
}

edge_t E[N * (N - 1) / 2];
int S[N];

int find_s(const int x)
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

float kruskal(std::priority_queue<edge_t> & q, int s)
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

float kruskal(int e, int s)
{
	std::sort(E, E + e);

	edge_t edge;
	float d = 0;
	while(e-- && s)
	{
		edge = E[e];
		if(union_s(edge.a, edge.b))
		{
			s--;
			d = D[edge.a][edge.b];
		}
	}

	return sqrt(d);
}

int main_kruskal() // 0.030 c++11 sort version, 0.000 c++11 priority queue version
{
	int n, p, s;// e;

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
			D[i][j] = D[j][i] = C[i].norm(C[j]);
			//E[e++] = {i, j};
			q.push({i, j});
		}

		for(int i = 0; i < p; ++i) // initialization union find
			S[i] = i;

		//printf("%.2f\n", kruskal(e, p - s));
		printf("%.2f\n", kruskal(q, p - s));
	}

	return 0;
}

int main()
{
//	return main_prim();
	return main_kruskal();
}

