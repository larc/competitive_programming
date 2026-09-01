#include <cstdio>

#define N 1'000'001
int main()
{
	int freq[N] = {};
	int n, a;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		++freq[a];
	}

	a = 1;
	for(int i = 2; i < N; ++i)
		if(freq[i] > freq[a])
			a = i;

	printf("%d\n", a);

	return 0;
}

