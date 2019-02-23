#include <cstdio>
#include <algorithm>

int main()
{
	int n, m, A[100], S[100];

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", A + i);
	
	std::sort(A, A + n);	
	m = n >> 1;

	if(n & 1)  S[m] = A[n - 1];
	for(int i = 0; i < m; i++)
	{
		S[i] = A[i << 1];
		S[n - i - 1] = A[(i << 1) + 1];
	}
	
	for(int i = 0; i < n; i++)
		printf("%d ", S[i]);
	putchar('\n');

	return 0;
}

