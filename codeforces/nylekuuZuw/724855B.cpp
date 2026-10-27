#include <cstdio>
#include <unordered_map>

int main()
{
	int n, a, n_blocks = 0;
	std::unordered_map<int, bool> S;

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

