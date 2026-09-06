#include <cstdio>
#include <vector>

int main()
{
	int n, q, op, x, t;
	std::vector<int> A[1000];

	scanf("%d %d", &n, &q);
	while(q--)
	{
		scanf("%d %d", &op, &t);
		switch(op)
		{
			case 0:
				scanf("%d", &x);
				A[t].push_back(x);
				break;
			case 1:
				if(size(A[t])) printf("%d", A[t][0]);
				for(unsigned i = 1; i < size(A[t]); ++i)
					printf(" %d", A[t][i]);
				printf("\n");
				break;
			case 2: A[t].clear();
				break;
		}
	}

	return 0;
}

