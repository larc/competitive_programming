#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
	int k, n, H[1001], a, m;

	scanf("%d", &k);
	while(k--)
	{
		memset(H, 0, sizeof(H));

		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			H[a]++;
		}

		m = a = 0;
		for(int i = n; i > 0; i--)
		{
			a += H[i];
			m = std::max(m, std::min(a, i));
		}

		printf("%d\n", m);
	}

	return 0;
}

