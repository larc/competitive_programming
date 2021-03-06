// 1047 - Zones

#include <cstdio>
#include <cstring>

#define N (1 << 20)

int ones(int s)
{
	int count = 0;

	while(s)
	{
		count++;
		s -= s & (-s);
	}

	return count;
}

int main()
{
	int * pow_set = new int[N];
	int common[10][2];
	int n, b, m, idx, k, j;

	int n_cases = 1;
	while(scanf("%d %d", &n, &b), n)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", &pow_set[1 << i]);

		scanf("%d", &m);
		for(int i = 0; i < m; ++i)
		{
			idx = 0;

			scanf("%d", &k);
			while(k--) 
			{
				scanf("%d", &j);
				idx |= 1 << (j - 1);
			}

			common[i][0] = idx;
			scanf("%d", &common[i][1]);
		}

		n = 1 << n;
		k = (1 << b) - 1;
		for(int i = k; i < n; ++i)
		{
			if(ones(i) == b && b > 1)
			{
				pow_set[i] = 0;

				idx = i;
				while(idx)
				{
					pow_set[i] += pow_set[idx & (-idx)];
					idx -= idx & (-idx);
				}
				
				j = 0;
				while(j < m)
				{
					if(ones(i & common[j][0]))
						pow_set[i] -= (ones(i & common[j][0]) - 1) * common[j][1];

					j++;
				}

			}
			if(ones(i) == b && pow_set[i] > pow_set[k]) k = i;
		}
		

		printf("Case Number  %d\n", n_cases++);
		printf("Number of Customers: %d\n", pow_set[k]);
		printf("Locations recommended:");

		j = 1;
		while(k)
		{
			if(k & 1) printf(" %d", j);
			k >>= 1;
			j++;
		}

		printf("\n\n");
	}
	
	delete [] pow_set;

	return 0;
}

