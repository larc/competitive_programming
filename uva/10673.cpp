#include <cstdio>

//mk + d = x = pm + q(m + 1)

int main()
{
	int x, k, q, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &x, &k);
		q = x % k;
		if(q) printf("%d %d\n", k - q, q);
		else printf("0 %d\n", k);
	}
	return 0;
}

