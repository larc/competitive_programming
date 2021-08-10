#include <cstdio>
#include <cstring>

int main()
{
	int A[11], n_cases, r;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		memset(A, 0, sizeof(A));
		for(int i = 0; i < 4; ++i)
		{
			scanf("%d", &r);
			++A[r];
		}

		r = 0;
		for(int i = 1; i < 11; ++i)
			r = r < A[i] ? A[i] : r;

		printf("%d\n", r > 2 ? 4 - r : 2);
	}

	return 0;
}

