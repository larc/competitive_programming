#include <cstdio>
#include <algorithm>


int weight(const int * A, const int n, int * P, const int i = 0)
{
	if(i == n)
		return std::max(std::max(P[0], P[1]), P[2]);

	int min = 12'000'001;
	for(int j = 0; j < 3; ++j)
	{
		if(P[j] + A[i] > min)
			continue;

		P[j] += A[i];
		min = std::min(min, weight(A, n, P, i + 1));
		P[j] -= A[i];
	}

	return min;
}

int main()
{
	int n;
	int A[12], P[3] = {};

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", A + i);

	printf("%d\n", weight(A, n, P));

	return 0;
}

