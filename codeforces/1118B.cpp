#include <cstdio>

#define N 200004

int main()
{
	int L[N] = {};
	int R[N] = {};
	int n, count, A[N];

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", A + i);
		L[i + 2] = L[i] + A[i];
	}
	
	for(int i = n - 1; i > 0; i--)
		R[i + 2] = R[i + 4] + A[i];
	
	for(int i = 0; i < n; i++)
		count += L[i] + R[i + 3] == L[i + 1] + R[i + 4];
	
	printf("%d\n", count);

	return 0;
}

