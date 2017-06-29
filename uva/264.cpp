#include <cstdio>
#include <cmath>

int main()
{
	int x, n, d;
	while(scanf("%d", &x) != EOF)
	{
		n = sqrt(2 * x);
		d = n * (n + 1) / 2;
		if(x <= d) d -= n--; 
		d = x - d;
		if(n % 2) printf("TERM %d IS %d/%d\n", x, d, n - d + 2);
		else printf("TERM %d IS %d/%d\n", x, n - d + 2, d);
	}
	return 0;
}

