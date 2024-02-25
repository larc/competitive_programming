#include <cstdio>
#include <algorithm>

#define N 5002

int rsq(const int a, const int b, int * ac)
{
	return ac[b] - ac[a - 1];
}

int main()
{
	int sec[N] = {}, ac_1[N], ac_2[N];
	int n, q, count, max, total, a, b, c, d;
	int L[N], R[N];

	scanf("%d %d", &n, &q);
	for(int i = 0; i < q; ++i)
	{
		scanf("%d %d", L + i, R + i);
		sec[L[i]]++;
		sec[R[i] + 1]--;
	}

	for(int i = 2; i <= n; ++i)
		sec[i] += sec[i - 1];

	ac_1[0] = ac_2[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		ac_1[i] = ac_1[i - 1] + (sec[i] == 1);
		ac_2[i] = ac_2[i - 1] + (sec[i] == 2);
	}

	total = 0;
	for(int i = 1; i <= n; ++i)
		if(sec[i] > 0) total++;

	max = 0;
	for(int i = 0; i < q; ++i)
	for(int j = i + 1; j < q; ++j)
	{
		if(L[i] < L[j])
		{
			a = L[i]; b = R[i];
			c = L[j]; d = R[j];
		}
		else
		{
			a = L[j]; b = R[j];
			c = L[i]; d = R[i];
		}

		count = rsq(a, b, ac_1) + rsq(c, d, ac_1);
		if(c <= b)
		{
			count += rsq(c, std::min(b, d), ac_2);
			count -= rsq(c, std::min(b, d), ac_1);
		}

		max = std::max(max, total - count);
	}

	printf("%d\n", max);

	return 0;
}

