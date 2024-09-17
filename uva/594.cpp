// 594 - One Little, Two Little, Three Little Endians

#include <cstdio>
#include <algorithm>

int main()
{
	int n;
	char * b = (char *) &n;

	while(scanf("%d", &n) != EOF)
	{
		printf("%d converts to ", n);
		for(int i = 0, j = 3; i < j; ++i, --j)
			std::swap(b[i], b[j]);

		printf("%d\n", n);
	}

	return 0;
}

