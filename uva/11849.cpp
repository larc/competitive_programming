#include <cstdio>

#define N 1000000

int main()
{
	int n, m, b, i, j;
	int A[N], B[N];

	while(scanf("%d %d", &n, &m), n, m)
	{
		i = 0;
		while(n--) scanf("%d", &A[i++]);

		j = 0;
		while(m--) scanf("%d", &B[j++]);

		n = i; m = j;
		b = i = j = 0;
		while(i < n && j < m)
			if(A[i] == B[j]) { b++; i++; j++; }
			else if(A[i] < B[j]) i++;
			else j++;

		printf("%d\n", b);
	}
	return 0;
}

