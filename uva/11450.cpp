// 11450 - Wedding shopping

#include <cstdio>
#include <cstring>

#define M 201
#define N 21

#define size(i) price[i][0]

int main()
{
	int price[N - 1][N];
	bool reachable[2][M];				// 0: reachable money g - 1 | 1: reachable money g
	int cases, money, n_garments, b, m;

	scanf("%d", &cases);

	while(cases--)
	{
		scanf("%d %d", &money, &n_garments);
		for(int g = 0; g < n_garments; ++g)
		{
			scanf("%d", &size(g));
			for(int i = 1; i <= size(g); ++i)
				scanf("%d", &price[g][i]);
		}
		
		memset(reachable, 0, sizeof(reachable));
		for(int i = 1; i <= size(0); ++i)
			if(money - price[0][i] >= 0)
				reachable[0][money - price[0][i]] = 1;

		b = 1;
		for(int g = 1; g < n_garments; ++g)
		{
			memset(reachable[b], 0, sizeof(reachable[b]));
			for(m = 0; m < money; ++m)
				if(reachable[!b][m])
				{
					for(int i = 1; i <= size(g); ++i)
						if(m - price[g][i] >= 0)
							reachable[b][m - price[g][i]] = 1;
				}

			b = !b;
		}

		for(m = 0; m <= money && !reachable[!b][m]; ++m);

		if(m > money) printf("no solution\n");
		else printf("%d\n", money - m);
	}

	return 0;
}

