// 10264 - The Most Potent Corner

#include <cstdio>

#define N 1 << 14

int main()
{
	int n, m, p, max;
	int weight[N];
	int potency[N];

	while(scanf("%d", &n) != EOF)
	{
		m = 1 << n;
		for(int i = 0; i < m; i++)
			scanf("%d", weight + i);
	
		for(int i = 0; i < m; i++)
		{
			if(i >= N) printf("%d %d\n", n, i);
			potency[i] = 0;
			for(int j = 0; j < n; j++)
				potency[i] += weight[i ^ (1 << j)];
		}
		
		max = 0;
		for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			p = potency[i] + potency[i ^ (1 << j)];
			if(p > max) max = p;
		}

		printf("%d\n", max);
	}

	return 0;
}

