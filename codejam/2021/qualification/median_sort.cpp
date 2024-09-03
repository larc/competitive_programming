#include <cstdio>
#include <vector>

int query(const int a, const int b, const int c)
{
	int m;
	printf("%d %d %d\n", a, b, c);
	fflush(stdout);

	scanf("%d", &m);

	return m == b ? 1 : (m == a ? 0 : 2);
}

void sort(std::vector<int> & X)
{
	size_t n = X.size();

	if(n < 3) return;

	std::vector<int> S[3];

	int p = X[0], q = X[n - 1];

	for(size_t i = 1; i < n - 1; ++i)
		S[query(p, X[i], q)].push_back(X[i]);

	for(auto & vi: S)
		sort(vi);

	X.clear();

	auto join = [&](const std::vector<int> & vi, const bool reverse)
	{
		if(reverse)
			X.insert(X.end(), vi.rbegin(), vi.rend());
		else
			X.insert(X.end(), vi.begin(), vi.end());
	};

	join(S[0], S[0].size() > 1 && query(S[0].front(), S[0].back(), p) != 1);
	X.push_back(p);
	join(S[1], S[1].size() > 1 && query(S[1].front(), S[1].back(), q) != 1);
	X.push_back(q);
	join(S[2], S[2].size() > 1 && query(q, S[2].front(), S[2].back()) != 1);
}

int main()
{
	int t, n, q, ans;
	std::vector<int> X;

	scanf("%d %d %d", &t, &n, &q);
	while(t--)
	{
		X.clear();
		for(int i = 0; i < n; ++i)
			X.push_back(i + 1);

		sort(X);
		for(const int i: X)
			printf("%d ", i);
		putchar('\n'); fflush(stdout);

		scanf("%d", &ans);
		if(ans == -1) break;
	}

	return 0;
}

