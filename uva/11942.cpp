// 11942 - Lumberjack Sequencing

#include <cstdio>

int main()
{
	int n;
	int beard[10];
	bool s2l, l2s;
	
	scanf("%d", &n);
	printf("Lumberjacks:\n");

	while(n--)
	{
		for(int i = 0; i < 10; ++i)
			scanf("%d", beard + i);

		s2l = l2s = 1;
		for(int i = 1; i < 10; ++i)
		{
			if(beard[i] <= beard[i - 1]) s2l = 0;
			if(beard[9 - i] <= beard[10 - i]) l2s = 0;
		}
		
		if(s2l || l2s) printf("Ordered\n");
		else printf("Unordered\n");
	}

	return 0;
}

