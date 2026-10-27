#include <cstdio>
#include <vector>

int main()
{
	int n, a, n_blocks = 0;
	std::vector<bool> S(1'000'000'002);

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		if(!S[a])
		{
			if(S[a - 1] && S[a + 1]) --n_blocks;
			if(!S[a - 1] && !S[a + 1]) ++n_blocks;
			S[a] = true;
		}
		printf("%d ", n_blocks);
	}
	printf("\n");

	return 0;
}

