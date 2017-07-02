#include <cstdio>
#include <cmath>

int main()
{
	unsigned int n, r;
	while(scanf("%d", &n) && n)
	{
		r = sqrt(n);
		if(r * r == n) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

