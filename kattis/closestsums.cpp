#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> S;
const int & closest_sum(const int & q)
{
	int i = std::lower_bound(S.begin(), S.end(), q) - S.begin();
	if(i == S.size()) return S.back();
	if(i == 0) return S.front();
	return q - S[i - 1] < S[i] - q ? S[i - 1] : S[i];
}

int main()
{
	int A[1000], n, q, n_case = 0;
	S.reserve(1000000);

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", A + i);

		for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			S.push_back(A[i] + A[j]);

		std::sort(S.begin(), S.end());

		printf("Case %d:\n", ++n_case);

		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &q);
			printf("Closest sum to %d is %d.\n", q, closest_sum(q));
		}

		S.clear();
	}

	return 0;
}

