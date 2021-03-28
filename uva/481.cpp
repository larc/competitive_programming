// 481 - What Goes Up

#include <cstdio>
#include <algorithm>

#define N 1000000

int seq[N];
int lis[N];
int lis_i[N];
int parent[N];

void print_lis(const int & i)
{
	if(i < 0) return;

	print_lis(parent[i]);
	printf("%d\n", seq[i]);
}

int main()
{
	int low, l_size, l_end, n;
	l_size = l_end = n = 0;

	while(scanf("%d", seq + n) != EOF)
	{
		low = std::lower_bound(lis, lis + l_size, seq[n]) - lis;
		lis[low] = seq[n];
		lis_i[low] = n;
		parent[n] = low ? lis_i[low - 1] : -1;

		if(low == l_size)
		{
			l_size++;
			l_end = n;
		}

		n++;
	}

	printf("%d\n", l_size);
	printf("-\n");
	print_lis(l_end);

	return 0;
}

