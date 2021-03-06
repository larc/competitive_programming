#include <cstdio>
#include <vector>

int main()
{
	std::vector<int> four; four.reserve(100);
	std::vector<int> two; two.reserve(20);
	
	int M[20][20] = {};
	int count[1001] = {};
	int n, m, a;
	
	scanf("%d", &n);
	for(int i = 0; i < n * n; ++i)
	{
		scanf("%d", &a);
		count[a]++;
	}

	m = n / 2;
	for(int i = 1; i < 1001; ++i)
	{
		while(count[i] >= 4 && four.size() < m * m)
		{
			four.push_back(i);
			count[i] -= 4;
		}
		while(count[i] >= 2 && two.size() < m << 1)
		{
			two.push_back(i);
			count[i] -= 2;
		}
		if(count[i] == 1)
			if(M[m][m])
			{
				printf("NO\n");
				return 0;
			}
			else M[m][m] = i; 
	}

	if(four.size() != m * m || ((n & 1) && (two.size() != m << 1 || !M[m][m])))
	{
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");

	a = 0;
	for(int i = 0; i < m; ++i)
	for(int j = 0; j < m; ++j)
	{
		M[i][j] = four[a];
		M[i][n - j - 1] = four[a];
		M[n - i - 1][j] = four[a];
		M[n - i - 1][n - j - 1] = four[a];
		a++;
	}
	
	if(n & 1)
	{
		a = 0;
		for(int i = 0; i < m; ++i)
		{
			M[m][i] = M[m][n - i - 1] = two[a++];
			M[i][m] = M[n - i - 1][m] = two[a++];
		}
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			printf("%d ", M[i][j]);
		putchar('\n');
	}

	return 0;
}

