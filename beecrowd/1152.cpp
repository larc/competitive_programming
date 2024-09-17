// 1152 - Dark Roads

#include <cstdio>
#include <queue>

#define N 200000


int S[N];

void reset_s(int n)
{
	while(n--) S[n] = n;
}

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

struct edge_t
{
	int x, y, w;
};

bool operator<(const edge_t & a, const edge_t & b)
{
	return a.w > b.w;
}

int main()
{
	edge_t e;
	int cost, path;
	int m, n, x, y, z;

	while(scanf("%d %d", &m, &n), m && n)
	{
		std::priority_queue<edge_t> q;

		cost = 0;
		while(n--)
		{
			scanf("%d %d %d", &x, &y, &z);
			q.push({x, y, z});
			cost += z;
		}

		reset_s(m);
		m--; // we need only m - 1 edges to connect m nodes

		path = 0;
		while(!q.empty() && m)
		{
			e = q.top();
			q.pop();

			if(union_s(e.x, e.y))
			{
				path += e.w;
				m--;
			}
		}

		printf("%d\n", cost - path);
	}

	return 0;
}

