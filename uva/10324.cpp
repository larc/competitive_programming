// 10324 - Zeros and Ones

#include <cstdio>
#include <algorithm>

#define N 1000001

int main()
{
	char line[N];
	int sum[N];
	int n, i, j, a, b, c = 1;

	while(scanf("%s", line) != EOF)
	{
		n = 1;
		sum[0] = line[0] - '0';
		while(line[n] != '\0')
		{
			sum[n] = sum[n - 1] + line[n] - '0';
			n++;
		}

		printf("Case %d:\n", c++);

		scanf("%d", &n);
		while(n--)
		{
			scanf("%d %d", &i, &j);
			a = std::min(i, j);
			b = std::max(i, j);

			i = sum[b] - sum[a] + line[a] - '0';
			j = b - a + 1;

			if(i == 0 || i == j) printf("Yes\n");
			else printf("No\n");
		}
	}

	return 0;
}

