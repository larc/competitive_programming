// 624 - CD

#include <cstdio>

int num[20];
int rseq, rest;

void tracks(const int & n, const int & r, const int & seq, const int & i)
{
	if(r < 0) return;

	if(r < rest)
	{
		rest = r;
		rseq = seq;
	}

	if(n == i) return;

	tracks(n, r - num[i], seq | (1 << i), i + 1);
	tracks(n, r, seq, i + 1);
}

int main()
{
	int s, n;
	while(scanf("%d %d", &s, &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", num + i);

		rest = s;
		tracks(n, s, 0, 0);

		for(int i = 0; i < n; ++i)
			if(rseq &  (1 << i))
				printf("%d ", num[i]);
		printf("sum:%d\n", s - rest);
	}

	return 0;
}

