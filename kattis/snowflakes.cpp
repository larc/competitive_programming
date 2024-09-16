#include <cstdio>
#include <map>

#define N 1000000


int main()
{
	std::map<int, int> last_idx;

	int n_cases, n;
	int m, k, idx, max, sf;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		max = m = 0;
		idx = 0;

		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &sf);

			if(k = last_idx[sf])
			{
				if(k > idx) idx = k;
				m = i - idx;
			}
			else m++;

			last_idx[sf] = i;
			if(m > max) max = m;
		}

		printf("%d\n", max);
		last_idx.clear();
	}

	return 0;
}

