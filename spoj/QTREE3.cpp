#include <cstdio>
#include <cstring>
#include <vector>

#define N 100001
#define L(i) ((i << 1) + 1)
#define R(i) ((i << 1) + 2)
#define P(i) ((i - 1) >> 1)

std::vector<int> G[N];

int heavy[N], level[N], parent[N];

int dfs(const int & u)
{
	heavy[u] = 0;

	int m_size, size, s;

	m_size = size = 0;
	for(const int & v: G[u])
	{
		if(v == parent[u]) continue;

		parent[v] = u;
		level[v] = level[u] + 1;
		
		size += s = dfs(v);
		if(m_size < s)
		{
			m_size = s;
			heavy[u] = v;
		}
	}

	return size + 1;
}

int head[N], pos[N], ipos[N], current;

void hld(const int & u, const int & h)
{
	head[u] = h;
	ipos[current] = u;
	pos[u] = current++;

	if(heavy[u]) hld(heavy[u], h);

	for(const int & v: G[u])
	{
		if(v == parent[u] || v == heavy[u])
			continue;

		hld(v, v);
	}
}

bool color[N];
int st[N << 2], idx[N];

int init_st(const int & n, const int & i, const int & j)
{
	if(i == j)
	{
		idx[i] = n;
		return st[n] = ipos[i];
	}

	int m = (i + j) >> 1;

	int l = init_st(L(n), i, m);
	int r = init_st(R(n), m + 1, j);

	return st[n] = color[l] >= color[r] ? l : r;
}

void update(int i)
{
	color[i] = !color[i];
	i = idx[pos[i]];

	do
	{
		i = P(i);

		const int & l = st[L(i)];
		const int & r = st[R(i)];
		st[i] = color[l] >= color[r] ? l : r;
	}
	while(i);
}

int rmq(const int & n, const int & i, const int & j, const int & a, const int & b)
{
	if(a <= i && j <= b) return st[n];
	if(j < a || b < i) return -1;

	int m = (i + j) >> 1;
	int l = rmq(L(n), i, m, a, b);
	int r = rmq(R(n), m + 1, j, a, b);

	if(l == -1) return r;
	if(r == -1) return l;

	return color[l] >= color[r] ? l : r;
}

int query(const int & a, const int & n)
{
	if(head[a] == 1)
	{
		int r = rmq(0, 0, n - 1, pos[1], pos[a]);

		if(color[r]) return r;
		return -1;
	}

	int r = rmq(0, 0, n - 1, pos[head[a]], pos[a]);
	if(!color[r]) r = -1;

	int q = query(parent[head[a]], n);

	return q != -1 ? q : r;
}

int main()
{
	memset(color, 0, sizeof(color));
	int n, m, u, v;

	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; ++i)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	level[1] = parent[1] = 0;
	dfs(1);
	
	current = 0;
	hld(1, 1);
	
	init_st(0, 0, n - 1);
	
	while(m--)
	{
		scanf("%d %d", &u, &v);
		if(!u) update(v);
		else printf("%d\n", query(v, n));
	}

	return 0;
}

