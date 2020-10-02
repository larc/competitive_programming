#include <cstdio>
#include <algorithm>

int main()
{
	int n_cases, n, n_str, S[2], i = 0;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		scanf("%d", S + i);
		
		n_str = -(--n);
		while(n--)
		{
			i = !i;
			scanf("%d", S + i);
			n_str += std::max(S[i] - S[!i], S[!i] - S[i]);
		}
		
		printf("%d\n", n_str);
	}

	return 0;
}

