#include <cstdio>
#include <algorithm>
#include <map>
#include <stack>

#define N 100000

int S[N];
std::map<int, int> dp[N];
std::map<int, int> sum[N];

int dfs(const int & m, int n)
{
	if(n < 0) return 0;

	int & r = dp[n][m];
	int & s = sum[n][m];
	if(r) return s;
	
	int u, d;
	while(n >= 0)
	{
		u = std::upper_bound(S, S + n, m - S[n]) - S;
		d = dfs(m - S[n], u - 1) + S[n];

		if(d > s)
		{
			s = d;
			r = n + 1;
		}
		
		n--;
	}
	
	return s;	
}

int main()
{
	int m, n;
	std::stack<int> ans;

	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; i++)
		scanf("%d", S + i);

	n--;
	fprintf(stderr, "MAX: %d\n", dfs(m, n));
	
	while(n >= 0)
	{
		n = dp[n][m] - 1;
		m -= S[n];
		
		ans.push(n);	
		
		n = std::upper_bound(S, S + n, m) - S - 1;
	}

	printf("%lu\n", ans.size());
	while(!ans.empty())
	{
		printf("%d ", ans.top());
		ans.pop();
	}
	putchar('\n');

	return 0;
}

