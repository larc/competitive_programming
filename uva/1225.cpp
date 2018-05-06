// 1225 - Digit Counting

#include <cstdio>
#include <cstring>

int main()
{
	int digits[10];
	int n_sets, n, x;
	
	scanf("%d", &n_sets);
	while(n_sets--)
	{
		scanf("%d", &n);

		memset(digits, 0, sizeof(digits));
		for(int i = 1; i <= n; i++)
		{
			x = i;
			while(x)
			{
				digits[x % 10]++;
				x /= 10;
			}
		}

		printf("%d", digits[0]);
		for(int i = 1; i < 10; i++)
			printf(" %d", digits[i]);
		printf("\n");
	}

	return 0;
}

