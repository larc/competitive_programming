#include <cstdio>

#define N 1000000

int main()
{
	int A[N], n, m, cd, b, i;

	while(scanf("%d %d", &n, &m) && n && m)
	{
		for(i = 0; i < n; ++i)
			scanf("%d", A + i);

		cd = i = 0;
		while(m--)
		{
			scanf("%d", &b);
			while(i < n && A[i] < b) ++i;
			if(i < n && A[i] == b) { ++cd; ++i; }
		}

		printf("%d\n", cd);
	}

	return 0;
}

