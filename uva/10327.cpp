#include <cstdio>

int main()
{
	int n, f;
	int num[1000];
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", num + i);
		
		f = 0;
		for(int i = 1; i < n; ++i)
		for(int j = 0; j < i; ++j)
			if(num[j] > num[i])
				f++;
		
		printf("Minimum exchange operations : %d\n", f);
	}
	return 0;
}

