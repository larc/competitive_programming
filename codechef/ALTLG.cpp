#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>

#define N 200001

typedef unsigned long long ull;

struct query_t
{
	char t;
	int l, r;
	ull ans;
};

ull gcd(const ull a, const ull b)
{
	return !b ? a : gcd(b, a % b);
}

ull lcm(const ull a, const ull b)
{
	return a / gcd(a, b) * b;
}

int A[N];
std::pair<int, ull> mq[2][N];	// [t][r] -> (l, ans)

ull (*const qfun[2]) (const ull, const ull) = {gcd, lcm};

ull & query(const bool t, int l, int r)
{
	bool op = t ? ((r - l) & 1) : !((r - l) & 1);

	int & last = mq[op][r].first;
	ull & q = mq[op][r].second;

	if(last)
	{
		r = last;
		op = t ? ((r - l) & 1) : !((r - l) & 1);
	}
	else q = A[r];

	last = l;
	while(l <= --r)
	{
		q = qfun[op](A[r], q);
		op = !op;
	}

	return q;
}

int main()
{
	int n_cases, n, nq;
	query_t Q[N];

	std::vector<int> iQ;
	iQ.reserve(N);

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		memset(mq, 0, sizeof(mq));

		scanf("%d %d", &n, &nq);
		for(int i = 1; i <= n; ++i)
			scanf("%d", A + i);

		for(int i = 0; i < nq; ++i)
		{
			query_t & q = Q[i];
			scanf("%hhd %d %d", &q.t, &q.l, &q.r);
			iQ.push_back(i);
		}

		std::sort(iQ.begin(), iQ.end(),
			[&Q](const int i, const int j)
			{
				const query_t & a = Q[i];
				const query_t & b = Q[j];
				return a.r == b.r ? a.l > b.l : a.r > b.r;
			});

		for(const int i: iQ)
		{
			query_t & q = Q[i];
			q.ans = query(q.t - 1, q.l, q.r); 
		}

		for(int i = 0; i < nq; ++i)
			printf("%llu\n", Q[i].ans);

		iQ.clear();
	}

	return 0;
}

