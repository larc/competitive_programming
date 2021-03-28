// 1237 - Expert Enough?

#include <cstdio>

#define N 10000

int main()
{
	int T, D, L[N], H[N], Q, P, n, s;
	char M[N][21];

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &D);
		for(int i = 0; i < D; ++i)
			scanf("%s %d %d", M[i], L + i, H + i);

		scanf("%d", &Q);
		while(Q--)
		{
			n = 0;
			scanf("%d", &P);

			for(int i = 0; i < D; ++i)
				if(L[i] <= P && P <= H[i])
				{
					n++;
					s = i;
				}


			if(n == 1) printf("%s\n", M[s]);
			else printf("UNDETERMINED\n");
		}

		if(T) putchar('\n');
	}

	return 0;
}

