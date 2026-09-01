#include <cstdio>
#include <algorithm>

int main()
{
	int n, a;
	int min_val, max_diff = -1;

	scanf("%d", &n);
	scanf("%d", &min_val);
	while(--n)
	{
		scanf("%d", &a);
		if(a > min_val)
			max_diff = std::max(max_diff, a - min_val);
		min_val = std::min(min_val, a);
	}

	printf("%d\n", max_diff);

	return 0;
}

