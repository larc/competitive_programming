#include <cstdio>
#include <algorithm>

#define N 200000

int main()
{
	int n, k, seq[N];

	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", seq + i);
	
	std::sort(seq, seq + n);
	
	if(k == n) printf("%d\n", seq[n - 1]);
	else if(k && k < n && seq[k - 1] < seq[k])
		printf("%d\n", seq[k - 1]);
	else if(!k && seq[0] > 1)
		printf("%d\n", seq[0] - 1);
	else printf("-1\n");

	return 0;
}

