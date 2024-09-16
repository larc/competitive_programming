// 1162 - Train Swapping

#include <cstdio>

int main()
{
	int n, L, i, j, s, aux;
	int T[50];

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &L);
		for(i = 0; i < L; ++i)
			scanf("%d", T + i);
		s = 0;
		for(i = 0; i < L; ++i)
			for(j = 0; j < L - i - 1; ++j)
				if(T[j] > T[j + 1])
				{
					aux = T[j];
					T[j] = T[j + 1];
					T[j + 1] = aux;
					s++;
				}

		printf("Optimal train swapping takes %d swaps.\n", s);
	}

	return 0;
}

