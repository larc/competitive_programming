#include <cstdio>
#include <algorithm>

int main()
{
	int mod[100] = {};
	int n, k, d, max;
	
	scanf("%d %d", &n, &k);
	while(n--)
	{
		scanf("%d", &d);
		mod[d % k]++;
	}

	max = 0;
	for(int i = 0; i <= k >> 1; ++i)
	{
		if(i == (k - i) % k)
			max += mod[i] >> 1;
		else max += std::min(mod[i], mod[k - i]);
	}

	printf("%d\n", max << 1);

	return 0;
}

