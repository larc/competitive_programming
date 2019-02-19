#include <cstdio>
#include <cmath>

#define N 100000

int main()
{
	int A[N], n, max, longest, l;

	scanf("%d", &n);

	max = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", A + i);
		if(max < A[i]) max = A[i];
	}

	longest = l = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] == max) l++;
		else l = 0;
		
		if(longest < l) longest = l;
	}
		
	printf("%d\n", longest);

	return 0;
}

