#include <cstdio>

int flapjacks[30];

void swap(int & a, int & b)
{
	int x = a;
	a = b;
	b = x;
}

void flip(int i, int j)
{
	for(; i < j; i++, j--)
		swap(flapjacks[i], flapjacks[j]);
}

int max(int i, const int & n)
{
	int m = i;
	for(; i < n; i++)
		if(flapjacks[i] > flapjacks[m])
			m = i;
	return m;
}

int main()
{
	int n = 0, i, j;
	char endl;
	while(scanf("%d", &flapjacks[n]) != EOF)
	{
		printf("%d", flapjacks[n++]);
		while(scanf("%c", &endl) && endl != '\n')
		{
			scanf("%d", &flapjacks[n]);
			printf(" %d", flapjacks[n++]);
		}
		printf("\n");
		
		flip(0, n - 1);

		for(i = 0; i < n; i++)
		{
			j = max(i, n);
			if(j > i)
			{
				printf("%d ", j + 1);
				flip(j, n - 1);
				printf("%d ", i + 1);
				flip(i, n - 1);
			}
		}

		printf("0\n");
		n = 0;
	}

	return 0;
}

