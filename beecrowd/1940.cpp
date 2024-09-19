// 1940 - Strategy Game

#include <cstdio>
#include <cstring>

#define N 500


int main()
{
	int scores[N];
	int points[N];
	int nj, nr;

	while(scanf("%d %d", &nj, &nr) != EOF)
	{
		memset(scores, 0, sizeof(scores));

		for(int i = 0; i < nr; ++i)
		for(int j = 0; j < nj; ++j)
		{
			scanf("%d", points + j);
			scores[j] += points[j];
		}

		nr = 0;
		for(int j = 0; j < nj; ++j)
			if(scores[j] >= scores[nr])
					nr = j;


		printf("%d\n", nr + 1);
	}

	return 0;
}

