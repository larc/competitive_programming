#include <cstdio>
#include <algorithm>

#define N 200001

int parent[N], num[N];
long long sum[N];

int find(const int & x)
{
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void init(const int & n)
{
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = parent[i + n] = i + n;
		sum[i] = sum[i + n] = i;
		num[i] = num[i + n] = 1;
	}
}

int main()
{
	int n, m, q, a, b, pa, pb;

	while(scanf("%d %d", &n, &m) != EOF)
	{
		init(n);

		while(m--)
		{
			scanf("%d", &q);
			switch(q)
			{
				case 1:	// union
					scanf("%d %d", &a, &b);
					pa = find(a);
					pb = find(b);
					if(pa != pb)
					{
						if(num[pa] > num[pb])
							std::swap(pa, pb);
						parent[pa] = pb;
						num[pb] += num[pa];
						sum[pb] += sum[pa];
					}
					break;

				case 2: // move
					scanf("%d %d", &a, &b);
					pa = find(a);
					pb = find(b);
					if(pa != pb)
					{
						parent[a] = pb;
						--num[pa];
						++num[pb];
						sum[pa] -= a;
						sum[pb] += a;
					}
					break;

				case 3:
					scanf("%d", &a);
					pa = find(a);
					printf("%d %lld\n", num[pa], sum[pa]);
					break;
			}
		}
	}

	return 0;
}

