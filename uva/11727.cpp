#include <cstdio>

int main()
{
	int t, x, y, z, r;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		if(y <= x && y <= z)
			r = x < z ? x : z;
		else if(x <= y && x <= z)
			r = y < z ? y : z;
		else	
			r = x < y ? x : y;
	
		printf("Case %d: %d\n", i, r);
	}

	return 0;
}
