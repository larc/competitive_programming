// Stacks

#include <cstdio>

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	int n, w, s = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &w);
		if(w) s++;
		else if(!i) s++;
	}

	w = n % s;
	n /= s;
	if(w)
	{
		printf("2\n");
		printf("%d %d\n", n + 1, w);
		printf("%d %d\n", n, s - w);
	}
	else
	{
		printf("1\n");
		printf("%d %d\n", n, s);
	}

	return 0;
}

