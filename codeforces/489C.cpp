#include <cstdio>
#include <cstring>

#define MM 100
#define SS 900

char num[MM + 1];
int dp[MM][SS + 1];

const char * get_num(const int & m)
{
	if(dp[m - 1][0] < 0) return "-1";
	
	int d = 0;
	for(int i = m - 1; i >= 0; i--)
	{
		num[i] = dp[i][d] + '0';
		d = dp[i][d] + d;
	}
	num[m] = 0;
	return num;
}

int main()
{
	int m, s, d;
	scanf("%d %d", &m, &s);
	
	if(m == 1 && !s)
	{
		printf("0 0\n");
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	for(int k = 1; k < 10; k++)
		if(s - k >= 0)
			dp[0][s - k] = k;
	
	for(int i = 1; i < m; i++)
	for(int j = 0; j <= s; j++)
		if(dp[i - 1][j] >= 0)
		{
			for(int k = 0; k < 10; k++)
				if(j - k >= 0)
					dp[i][j - k] = k;
		}
	
	printf("%s ", get_num(m));

	memset(dp, -1, sizeof(dp));
	for(int k = 1; k < 10; k++)
		if(s - k >= 0)
			dp[0][s - k] = k;
	
	for(int i = 1; i < m; i++)
	for(int j = s; j >= 0; j--)
		if(dp[i - 1][j] >= 0)
		{
			for(int k = 0; k < 10; k++)
				if(j - k >= 0)
					dp[i][j - k] = k;
		}
	
	printf("%s\n", get_num(m));

	return 0;
}

