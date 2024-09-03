#include <cstdio>
#include <cstring>

#define S 101

int main()
{
	int T, N, k, r, c;
	int M[S][S];
	bool rep[S];

	scanf("%d", &T);
	for(int x = 1; x <= T; ++x)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%d", &M[i][j]);

		k = 0;
		for(int i = 0; i < N; ++i)
			k += M[i][i];

		r = 0;
		for(int i = 0; i < N; ++i)
		{
			memset(rep, 0, sizeof(rep));
			for(int j = 0; j < N; ++j)
				if(rep[M[i][j]])
				{
					r++;
					break;
				}
				else rep[M[i][j]] = true;
		}

		c = 0;
		for(int j = 0; j < N; ++j)
		{
			memset(rep, 0, sizeof(rep));
			for(int i = 0; i < N; ++i)
				if(rep[M[i][j]])
				{
					c++;
					break;
				}
				else rep[M[i][j]] = true;
		}

		printf("Case #%d: %d %d %d\n", x, k, r, c);
	}

	return 0;
}

