#include <cstdio>

#define N 100'001

int main()
{
	int n, a, n_rem = 0, max_a;
	int freq[N] = {};

	scanf("%d", &n);

	max_a = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		a < N ? ++freq[a] : ++n_rem;
		if(a > max_a) max_a = a;
	}
	if(max_a > N) max_a = N;
	for(int i = 1; i <= max_a; ++i)
		n_rem += freq[i] < i ? freq[i] : freq[i] - i;

	printf("%d\n", n_rem);

	return 0;
}

