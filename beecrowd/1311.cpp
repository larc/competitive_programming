// 1311 - Army Buddies

#include <cstdio>

#define N 100001

int line[N][2];

#define pred(i) line[i][0]
#define succ(i) line[i][1]

int main()
{
	int b, s, l, r;
	while(scanf("%d %d", &s, &b), s || b)
	{
		for(int i = 1; i <= s; ++i)
		{
			pred(i) = i - 1;
			succ(i) = i + 1;
		}

		succ(s) = 0;

		while(b--)
		{
			scanf("%d %d", &l, &r);

			succ(pred(l)) = succ(r);
			pred(succ(r)) = pred(l);
			l = pred(l);
			r = succ(r);

			if(l && r) printf("%d %d\n", l, r);
			else if(!l && r) printf("* %d\n", r);
			else if(l && !r) printf("%d *\n", l);
			else printf("* *\n");
		}

		printf("-\n");
	}

	return 0;
}

