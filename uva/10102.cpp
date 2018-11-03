// 10102 - The path in the colored field

#include <cstdio>
#include <algorithm>

#define N 100000
#define INF (1ll << 31) - 1

int main()
{
	int A[N][2], sa;
	int B[N][2], sb;
	int m, min, max;
	char str[1024];

	while(scanf("%d", &m) != EOF)
	{
		sa = sb = 0;
		for(int i = 0; i < m; i++)
		{
			scanf("%s", str);
			for(int j = 0; j < m; j++)
				if(str[j] == '1')
				{
					A[sa][0] = i;
					A[sa++][1] = j;
				}
				else if(str[j] == '3')
				{
					B[sb][0] = i;
					B[sb++][1] = j;
				}
		}
		
		max = 0;
		for(int i = 0; i < sa; i++)
		{
			min = INF;
			for(int j = 0; j < sb; j++)
				min = std::min(min, abs(A[i][0] - B[j][0]) + abs(A[i][1] - B[j][1]));

			max = std::max(max, min);
		}

		printf("%d\n", max);
	}
	return 0;
}

