// 10334 - Ray Through Glasses

#include <cstdio>
#include <algorithm>

#define N 1003
#define M 211

void to_char(char * num, int n)
{
  std::reverse(num, num + n);

  num[n] = '\0';
  while(n--) num[n] += '0';
}

int main()
{
	int size[N] = {};
	char F[N][M] = {};
	
	F[1][0] = 1;
	size[0] = size[1] = 1;

	for(int i = 2; i < N; i++)
	{
		int a = 0;
		for(int k = 0; k < size[i - 1]; k++)
		{
			F[i][k] = F[i - 1][k] + F[i - 2][k] + a;
			
			a = F[i][k] / 10;
			F[i][k] %= 10;
		}

		size[i] = size[i - 1];
		if(a) F[i][size[i]++] = a;
	}
	
	for(int i = 0; i < N; i++)
		to_char(F[i], size[i]);
	
	int n;
	while(scanf("%d", &n) != EOF)
		printf("%s\n", F[n + 2]);
	
	return 0;
}

