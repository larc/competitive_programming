// Sorting

#include <cstdio>
#include <cstring>

#define N 200001

int array[N];
int aux[N];

void merge(const int & i, const int & m, const int & j)
{
	int a = i;
	int b = m + 1;
	int c = i;
	while(a <= m && b <= j)
		if(array[a] < array[b])
			aux[c++] = array[a++];
		else
			aux[c++] = array[b++];
	
	while(a <= m) aux[c++] = array[a++];
	while(b <= j) aux[c++] = array[b++];

	memcpy(array + i, aux + i, sizeof(int) * (j - i + 1));
}

void merge_sort(const int & i, const int & j)
{
	if(i == j) return;
	
	int m = (i + j) >> 1;
	merge_sort(i, m);
	merge_sort(m + 1, j);
	
	merge(i, m, j);

	printf("%d %d %d %d\n", i, j, array[i], array[j]);
}

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", array + i);
	
	merge_sort(1, n);
	
	printf("%d", array[1]);
	for(int i = 2; i <= n; i++)
		printf(" %d", array[i]);
	
	printf("\n");

	return 0;
}

