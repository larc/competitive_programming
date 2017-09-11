#include <cstdio>

#define N 1001

int set[N];

void init_set(const int & n)
{
	for(int i = 1; i <= n; i++)
		set[i] = i;
}

int find_set(const int & x)
{
	if(set[x] == x) return x;
	return set[x] = find_set(set[x]);
}

void union_set(const int & x, const int & y)
{
	set[find_set(x)] = find_set(y);
}

int main()
{
	int t, n, x, y, s, u;
	char c;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d\n", &n);
		init_set(n);
		s = u = 0;

		while(c = getchar(), c == 'c' || c == 'q')
		{
			scanf("%d %d", &x, &y);
			getchar();
			if(c == 'c') union_set(x, y);
			else find_set(x) == find_set(y) ? s++ : u++ ;
		}
		
		printf("%d,%d\n", s, u);
		if(t) printf("\n");
	}

	return 0;
}

