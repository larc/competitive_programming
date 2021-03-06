#include <cstdio>
#include <algorithm>

struct activity
{
	int s, e, i;

	bool operator < (const activity & a)
	{
		return s == a.s ? e < a.e : s < a.s;
	}
};

int main()
{
	int T, N, J, C;
	activity A[1001];
	char ans[1001];

	scanf("%d", &T);
	for(int x = 1; x <= T; ++x)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
		{
			A[i].i = i;
			scanf("%d %d", &A[i].s, &A[i].e);
		}

		std::sort(A, A + N);

		J = C = 0;
		for(int i = 0; i < N; ++i)
		{
			if(C <= A[i].s)
			{
				ans[A[i].i] = 'C';
				C = A[i].e;
			}
			else if(J <= A[i].s)
			{
				ans[A[i].i] = 'J';
				J = A[i].e;
			}
			else
			{
				*ans = 0;
				break;
			}
		}

		ans[N] = 0;

		printf("Case #%d: %s\n", x, *ans ? ans : "IMPOSSIBLE");
	}

	return 0;
}

