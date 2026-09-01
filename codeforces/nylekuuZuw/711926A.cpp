#include <cstdio>

int main()
{
	int A[4001] = {};
	int n, p, q;
	char op[4];

	scanf("%d %d", &n, &q);

	n = 0;
	while(q--)
	{
		scanf("%s %d", op, &p);
		if(*op == 'I')
		{
			for(int i = n; i > p; --i)
				A[i] = A[i - 1];
			scanf("%d", A + p);
			++n;
		}	
		else if(*op == 'D')
		{
			if(p == n) continue;
			--n;
			for(int i = p; i < n; ++i)
				A[i] = A[i + 1];
		}
	}

	for(int i = 0; i < n; ++i)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}

