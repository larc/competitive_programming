// 1300 - Hours and Minutes

#include <cstdio>

int main()
{
	int a;
	while(scanf("%d", &a) != EOF)
	{
		if(a % 6) printf("N\n");
		else printf("Y\n");
	}

	return 0;
}

