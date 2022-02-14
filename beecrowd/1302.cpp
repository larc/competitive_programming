// 1302 - Joining Couples

#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 100001

int parent[N];		// connected components
int flight[N];
int loop[N];
int size[N];
int level[N];

void init_p(const int & n)
{
	for(int i = 1; i <= n; ++i)
		parent[i] = i;
}

int find_p(const int & x)
{
	if(parent[x] == x) return x;
	return parent[x] = find_p(parent[x]);
}

bool union_p(int x, int y)
{
	x = find_p(x);
	y = find_p(y);

	if(x == y) return 0;

	parent[x] = y;
	return 1;
}

int update_level(const int & i)
{
	if(level[i]) return level[i] < 0 ? 0 : level[i];
	return level[i] = 1 + update_level(flight[i]);
}

int loop_flights(int & a, int & b, const int & s)
{
	a = s + level[a];
	b = s + level[b];
	if(a > b) a -= b;
	else a = b - a;
	b = s - a;
	return a < b ? a : b;
}

int main()
{
	int m, n, q, a, b;
	while(scanf("%d", &n) != EOF)
	{
		init_p(n);

		m = 0;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", flight + i);
			if(!union_p(flight[i], i)) // loop;
				loop[m++] = i;
		}

		memset(level + 1, 0, sizeof(int) * n);
		for(int i = 0; i < m; ++i)
		{
			int & s = size[find_p(loop[i])]; // component's loop size
			s = 0;
			a = b = loop[i];
			do
			{
				s++;
				level[b] = -s;
				b = flight[b];
			}
			while(a != b);
		}

		for(int i = 1; i <= n; ++i)
			update_level(i);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &a, &b);
			if(find_p(a) != find_p(b)) printf("-1\n");
			else
			{
				int & s = size[find_p(a)]; // component's loop size
				if(level[a] < 0 && level[b] < 0)
					printf("%d\n", loop_flights(a, b, s));
				else
				{
					if(level[b] > level[a])
						std::swap(a, b);

					m = level[b] > 0 ? level[a] - level[b] : level[a];
					n = m;

					while(m--) a = flight[a];
					m = level[a] > 0 ? level[a] : 0;

					// lca
					while(m && a != b)
					{
						m--;
						n += 2;
						a = flight[a];
						b = flight[b];
					}

					if(m) printf("%d\n", n);
					else printf("%d\n", n + loop_flights(a, b, s));
				}
			}
		}
	}

	return 0;
}

