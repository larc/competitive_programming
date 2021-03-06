// 10656 - Maximum Sum (II)

#include <cstdio>

#define N 1001

int main()
{
	int seq[N];;
	int n, s, num;

	while(scanf("%d", &n) != EOF && n)
	{
		s = 0;
		while(n--)
		{
			scanf("%d", &num);
			if(num) seq[s++] = num;
		}
		
		s--;
		for(int i = 0; i < s; ++i)
			printf("%d ", seq[i]);

		printf("%d\n", s < 0 ? 0 : seq[s]);
	}

	return 0;
}

