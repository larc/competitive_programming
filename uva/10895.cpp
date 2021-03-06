// 10895 - Matrix Transpose

#include <cstdio>
#include <map>

#define N 10001

int main()
{
	std::map<int, int> matrix[N];
	int idx[N];

	int m, n, r, val;
	while(scanf("%d %d", &m, &n) != EOF)
	{
		for(int j = 1; j <= m; ++j)
		{
			scanf("%d", &r);
			for(int i = 0; i < r; ++i)
				scanf("%d", idx + i);
			
			for(int i = 0; i < r; ++i)
			{
				scanf("%d", &val);
				matrix[idx[i]][j] = val;
			}
		}

		printf("%d %d\n", n, m);
		for(int i = 1; i <= n; ++i)
		{
			printf("%d", r = matrix[i].size());
			for(auto & p: matrix[i])
				printf(" %d", p.first);
			putchar('\n');
			
			for(auto & p: matrix[i])
			{
				printf("%d", p.second);
				if(--r) putchar(' ');
			}
			putchar('\n');
		}

		for(int i = 1; i <= n; ++i)
			matrix[i].clear();
	}

	return 0;
}

