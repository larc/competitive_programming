#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 32

struct contestant
{
	int c, p, t;

	bool operator < (contestant & r)
	{
		if(p != r.p) return p > r.p;
		if(t != r.t) return t < r.t;
		return c < r.c;
	}
};

int main()
{
	int cases, c, p, t;
	char l;
	char line[N];

	int times[101][10];
	bool solved[101][10];
	contestant rank[100];

	scanf("%d", &cases);
	l = getchar();
	l = getchar();
	while(cases--)
	{
		memset(times, 0, sizeof(times));
		memset(solved, 0, sizeof(solved));

		while(fgets(line, N, stdin) && line[0] != '\n' )
		{
			sscanf(line, "%d %d %d %c", &c, &p, &t, &l);

			times[c][0]++; //submisions
			if(!solved[c][p])
			{
				if(l == 'C')
				{
					solved[c][p] = 1;
					times[c][p] = t - times[c][p];
				}
				else if(l == 'I')
					times[c][p] -= 20;
			}
		}

		c = 0;
		for(int i = 1; i < 101; ++i)
		{
			if(times[i][0]) // contestant have submissions
			{
				rank[c].c = i;
				rank[c].p = 0;
				rank[c].t = 0;

				for(p = 1; p <= 9; ++p)
					if(solved[i][p])
					{
						rank[c].p++;
						rank[c].t += times[i][p];
					}

				c++;
			}
		}

		std::sort(rank, rank + c);
		for(int i = 0; i < c; ++i)
			printf("%d %d %d\n", rank[i].c, rank[i].p, rank[i].t);

		if(cases) printf("\n");
	}

	return 0;
}

