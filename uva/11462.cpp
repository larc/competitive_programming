// 11462 - Age Sort

#include <cstdio>
#include <cstring>


int main()
{
	const char sep[3] = "\n ";
	int ages[101];
	int n, x;

	while(scanf("%d", &n) != EOF && n)
	{
		memset(ages, 0, sizeof(ages));

		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			++ages[x];
		}

		for(int i = 1; i <= 100; ++i)
			while(ages[i]--)
				printf("%d%c", i, sep[--n > 0]);
	}

	return 0;
}

