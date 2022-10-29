// 12299 - RMQ with Shifts

#include <cstdio>
#include <algorithm>

#define N 100001
#define left(n) ((n) << 1)
#define right(n) ((n) << 1) + 1
#define parent(n) ((n) >> 1)

int A[N];
int A_st[N];

struct segment_tree
{
	int values[N << 2];

	segment_tree()
	{
		for(int i = 0; i < (N << 2); ++i)
			values[i] = N;
	}

	const int & build(const int & n, const int & l, const int & r)
	{
		if(l == r)
		{
			A_st[l] = n;
			return values[n] = A[l];
		}

		const int & m = (l + r) >> 1;
		return values[n] = std::min(build(left(n), l, m), build(right(n), m + 1, r));
	}

	int rmq(const int & n, const int & l, const int & r, const int & a, const int & b)
	{
		if(r < a || b < l) return N;
		if(a <= l && r <= b) return values[n];

		const int & m = (l + r) >> 1;
		return std::min(rmq(left(n), l, m, a, b), rmq(right(n), m + 1, r, a, b));
	}

	void update(int n, const int & v)
	{
		if(!n) return;

		values[n] = v;
		n = parent(n);
		while(n)
		{
			values[n] = std::min(values[left(n)], values[right(n)]);
			n = parent(n);
		}
	}
};

int main()
{
	segment_tree st;
	int n, q, a, b;
	char str[32];

	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", A + i);

	st.build(1, 1, n);

	while(q--)
	{
		scanf("%s", str);
		if(str[0] == 'q')
		{
			b = 0;
			for(int i = 6; str[i] != ')'; ++i)
				if(str[i] != ',')
					b = b * 10 + str[i] - '0';
				else
				{
					a = b;
					b = 0;
				}

			printf("%d\n", st.rmq(1, 1, n, a, b));
		}
		else
		{
			a = b = 0;
			for(int i = 6; str[i]; ++i)
				if(str[i] != ',' && str[i] != ')')
					b = b * 10 + str[i] - '0';
				else
				{
					st.update(A_st[a], A[b]);
					A[a] = A[b];
					a = b;
					b = 0;
				}

			st.update(A_st[a], A[b]);
			A[a] = A[b];
		}
	}

	return 0;
}

