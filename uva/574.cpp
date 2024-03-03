// 574 - Sum It Up

#include <cstdio>
#include <cstring>
#include <string>
#include <set>

char sum[64];
int num[12];
int seq[12];

std::set<std::string> sums;
int sum_it_up(const int n, const int s, const int p, int i)
{
	if(p == n && s) return 0;
	if(!s)
	{
		i = sprintf(sum, "%d", seq[0]);
		for(int j = 1; j < p; ++j)
			i += sprintf(sum + i, "+%d", seq[j]);

		if(sums.insert(sum).second) printf("%s\n", sum);
		return 1;
	}

	int count = 0;
	for(; i < n; ++i)
		if(num[i] <= s)
		{
			seq[p] = num[i];
			count += sum_it_up(n, s - seq[p], p + 1, i + 1);
		}

	return count;
}

int main()
{
	int s, n;
	while(scanf("%d %d", &s, &n), n)
	{
		sums.clear();

		for(int i = 0; i < n; ++i)
			scanf("%d", num + i);

		printf("Sums of %d:\n", s);
		if(!sum_it_up(n, s, 0, 0)) printf("NONE\n");
	}

	return 0;
}

