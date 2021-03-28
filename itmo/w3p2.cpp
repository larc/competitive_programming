// Inversions

#include <cstdio>
#include <cstring>

#define N 1000000

typedef unsigned long long ull;

int array[N];
int aux[N];

// return the number of inversions in merge step
ull merge(const int & i, const int & m, const int & j)
{
	ull inv = 0;

	int a = i;
	int b = m + 1;
	int c = i;
	while(a <= m && b <= j)
		if(array[a] <= array[b])
			aux[c++] = array[a++];
		else
		{
			aux[c++] = array[b++];
			inv += m - a + 1;
		}

	while(a <= m) aux[c++] = array[a++];
	while(b <= j) aux[c++] = array[b++];

	memcpy(array + i, aux + i, sizeof(int) * (j - i + 1));

	return inv;
}

ull merge_sort(const int & i, const int & j)
{
	if(i == j) return 0;

	int m = (i + j) >> 1;
	ull inv = 0;
	inv += merge_sort(i, m);
	inv += merge_sort(m + 1, j);

	return inv + merge(i, m, j);
}

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", array + i);

	printf("%llu\n", merge_sort(0, n - 1));

	return 0;
}

