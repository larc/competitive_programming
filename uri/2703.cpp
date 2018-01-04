// 2703 - Imperial Roads
// ACM ICPC 2017 - South America

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

#define N 100001
#define M 200002
#define LG_M 15 // lg(M)
#define LG_N 14 // lg(N)

struct union_find
{
	int parent[N];

	void init(const int n)
	{
		for(int i = 1; i <= n; i++)
			parent[i] = i;
	}

	const int & find(const int & x)
	{
		if(x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);
		if(x == y) return 0;

		parent[x] = y;
		return 1;
	}

} uf;

struct edge_t
{
	int u, v, w;

} roads[M];

bool operator < (const edge_t & a, const edge_t & b)
{
	return a.w > b.w;
}

std::map<int, int> G[N];		// graph
std::map<int, bool> T[N];		// minimum spanning tree

int kruskal(int n, const int & m)
{
	uf.init(n--);
	std::priority_queue<edge_t> q(roads, roads + m);
	
	edge_t e;
	int cost = 0;
	while(!q.empty() && n)
	{
		e = q.top();
		q.pop();

		if(uf.join(e.u, e.v))
		{
			T[e.u][e.v] = 1;
			T[e.v][e.u] = 1;
			cost += e.w;
			n--;
		}
	}

	return cost;
}

struct RMQ_LCA
{
	const int * A;
	int ST[M][LG_M];

	void init(const int * _A, const int & n)
	{
		A = _A;
		for(int i = 0; i < n; i++)
			ST[i][0] = i;

		for(int j = 1; (1 << j) <= n; j++)
		for(int i = 0; i + (1 << j) - 1 < n; i++)
			if(A[ST[i][j - 1]] < A[ST[i + (1 << (j - 1))][j - 1]])
				ST[i][j] = ST[i][j - 1];
			else
				ST[i][j] = ST[i + (1 << (j - 1))][j - 1];

	}

	int query(const int & i, const int & j)
	{
		int k = log2(j - i + 1);
		if(A[ST[i][k]] < A[ST[j - (1 << k) + 1][k]])
			return ST[i][k]; 

		return ST[j - (1 << k) + 1][k];
	}

} rmq;

int L[M], E[M], H[N], idx;
int leaves[N], n_leaves;
int heavy[N], size_tree[N];

void dfs(const int & u, const int & level, const bool & d)
{
	if(H[u] > -1) return;

	H[u] = idx;
	E[idx] = u;
	L[idx++] = level;
	
	int v;
	heavy[u] = -1;
	for(auto & p: T[u])
	{
		v = p.first;
		if(p.second)
		{
			if(d) T[v][u] = 0;
			if(heavy[u] == -1 || size_tree[heavy[u]] < size_tree[v])
				heavy[u] = v;
		
			dfs(v, level + 1, d);
			
			E[idx] = u;
			L[idx++] = level;
		}
	}

	size_tree[u] = heavy[u] == -1 ? 1 : 1 + size_tree[heavy[u]];
	if(size_tree[u] == 1) leaves[n_leaves++] = u;
}

void dfs(const int & u, const int & d = 0)
{
	idx = 0;
	n_leaves = 0;
	memset(H, -1, sizeof(H));
	dfs(u, 0, d);
}

int lca(const int & u, const int & v)
{
	return H[u] < H[v] ? E[rmq.query(H[u], H[v])] : E[rmq.query(H[v], H[u])]; 
}

struct path_t
{
	int * P;
	int size;
	int root;
	
	void init(int * p, int r)
	{
		P = p;
		root = r;
		size = 0;
	}

	void add(const int & w)
	{
		P[size++] = w;
	}

} paths[N];

int n_paths;
int pedges[N];
int pbase[N];
int pindex[N];

// Heavy Light Decomposition
void path_decomposition(const int & u)
{
	int & h = heavy[u];
	path_t & p = paths[n_paths - 1]; // current path (heavy)

	if(h != -1)
	{
		pbase[h] = n_paths - 1;
		pindex[h] = p.size;
		p.add(G[u][h]);

		path_decomposition(h);
	}

	for(auto & e: T[u])
	{
		const int & v = e.first;
		if(e.second && v != h)
		{
			paths[n_paths].init(p.P + p.size, u);

			pbase[v] = n_paths;
			pindex[v] = 0;
			paths[n_paths].add(G[u][v]);
			n_paths++;

			path_decomposition(v);
		}
	}
}

struct RMQ
{
	static const int * A;
	int ST[N][LG_N];

	void init(const int & n, const int & d)
	{
		for(int i = 0; i < n; i++)
			ST[i + d][0] = i;

		for(int j = 1; (1 << j) <= n; j++)
		for(int i = 0; i + (1 << j) - 1 < n; i++)
			if(A[ST[i + d][j - 1] + d] > A[ST[i + d + (1 << (j - 1))][j - 1] + d])
				ST[i + d][j] = ST[i + d][j - 1];
			else
				ST[i + d][j] = ST[i + d + (1 << (j - 1))][j - 1];

	}

	int query(const int & i, const int & j, const int & d)
	{
		int k = log2(j - i + 1);
		if(A[ST[i + d][k] + d] > A[ST[j - (1 << k) + 1 + d][k] + d])
			return A[ST[i + d][k] + d]; 

		return A[ST[j - (1 << k) + 1 + d][k] + d];
	}

} prmq;

const int * RMQ::A = pedges;

int max_edge_path(const int & v, const int & u)
{
	if(v == u) return 0;
	
	int & p = pbase[v];
	if(p == pbase[u]) return prmq.query(pindex[u] + 1, pindex[v], paths[p].P - pedges);
	
	return std::max(prmq.query(0, pindex[v], paths[p].P - pedges), max_edge_path(paths[p].root, u));
}

int main()
{

	int n, m, q, u, v, w;
	int cost;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			G[i].clear();
			T[i].clear();
		}

		for(int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			roads[i] = {u, v, w};
			G[u][v] = G[v][u] = w;
		}

		cost = kruskal(n, m);
		
		// find the longest path
		dfs(1);
		
		u = 0;
		for(int i = 1; i < n_leaves; i++)
			if(L[H[leaves[u]]] < L[H[leaves[i]]]) u = i;
		
		u = leaves[u];
		dfs(u, 1);
		
		// init RMQ for LCA
		rmq.init(L, idx);

		// find path decomposition
		n_paths = 1;
		paths[0].init(pedges, u);
		pbase[u] = pindex[u] = -1;
		path_decomposition(u);

		for(int i = 0; i < n_paths; i++)
			prmq.init(paths[i].size, paths[i].P - pedges);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &u, &v);
			if(T[u][v] || T[v][u]) printf("%d\n", cost);
			else
			{
				w = lca(u, v);
				printf("%d\n", cost + G[u][v] - std::max(max_edge_path(u, w), max_edge_path(v, w)));
			}
		}
	}
	
	return 0;
}

