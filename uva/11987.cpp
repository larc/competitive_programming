#include <cstdio>
#include <cstring>

const int N = 200001;

int n, m, parent[N], num[N], sum[N];

int find(int x)
{
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void init()
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
	while (~scanf("%d%d", &n, &m))
	{
		int q, a, b;
		init();
		while(m--)
		{
			scanf("%d", &q);
			if (q == 1)
			{
				scanf("%d%d", &a, &b);
				int pa = find(a);
				int pb = find(b);
				if (pa == pb) continue;
				parent[pa] = pb;
				num[pb] += num[pa];
				sum[pb] += sum[pa];
			}
			else if (q == 2)
			{
				scanf("%d%d", &a, &b);
				int pa = find(a);
				int pb = find(b);
				if (pa == pb) continue;
				parent[a] = pb;
				num[pa]--;
				num[pb]++;
				sum[pa] -= a;
				sum[pb] += a;
			}
			else
			{
				scanf("%d", &a);
				int pa = find(a);
				printf("%d %d\n", num[pa], sum[pa]);
			}
		}
	}
	return 0;
}
