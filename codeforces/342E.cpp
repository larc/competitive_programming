#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define N 100001

int ftl[N], ftr[N];		// min Fenweick Tree (min BIT): min l-range [1:i], min r-range [i:h_size]

void update_ft(int i, int val, int * ft, const int & n)
{
	while(i <= n)
	{
		ft[i] = std::min(ft[i], val);

		val += i & -i;
		i += i & -i; 
	}
}

int min_ft(int i, int * ft)
{
	int min = N;
	int j = 0;

	while(i)
	{
		min = std::min(min, ft[i] + j);
		j += i & -i;
		i -= i & -i;
	}

	return min;
}

std::vector<int> G[N];

int heavy[N], parent[N];

int dfs(const int & u)
{
	heavy[u] = 0;

	int m_size, size, s;
	
	m_size = size = 0;
	for(const int & v: G[u])
	{
		if(v == parent[u]) continue;

		parent[v] = u;
		size += s = dfs(v);
		if(m_size < s)
		{
			m_size = s;
			heavy[u] = v;
		}
	}

	return size + 1;
}

int head[N], pos[N], h_size[N], current;

void hld(const int & u, const int & h)
{
	head[u] = h; 
	h_size[h]++;
	pos[u] = current++;

	if(heavy[u]) hld(heavy[u], h);

	for(const int & v: G[u])
	{
		if(v == parent[u] || v == heavy[u])
			continue;
		
		h_size[v] = 0;
		hld(v, v);
	}
}

inline int ft_i(const int & u)
{
	return pos[u] - pos[head[u]] + 1;
}

void change_color(const int & u, const int & val)
{
	const int & h = head[u];
	const int & p = parent[h];
	
	update_ft(ft_i(u), val, ftl + pos[h] - 1, h_size[h]);
	update_ft(h_size[h] - ft_i(u) + 1, val, ftr + pos[h] - 1, h_size[h]);
	
	if(!p) return;

	change_color(p, min_ft(h_size[h], ftr + pos[h] - 1) + 1);
}

int min_dist(const int & u)
{
	if(!u) return N;

	int d = std::min(min_ft(ft_i(u), ftl + pos[head[u]] - 1), 
					min_ft(h_size[head[u]] - ft_i(u) + 1, ftr + pos[head[u]] - 1));

	return std::min(d, min_dist(parent[head[u]]) + 1 + pos[u] - pos[head[u]]);
}

int main()
{
	int n, q, u, v;

	scanf("%d %d", &n, &q);
	for(int i = 0; i <= n; ++i)
		ftl[i] = ftr[i] = N;
	
	for(int i = 1; i < n; ++i)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	current = 0; 
	parent[1] = h_size[1] = 0;
	dfs(1); hld(1, 1);
	change_color(1, 0);

	while(q--)
	{
		scanf("%d %d", &u, &v);
		if(u == 1) change_color(v, 0);
		else printf("%d\n", min_dist(v));
	}

	return 0;
}

