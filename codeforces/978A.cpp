#include <cstdio>

int main()
{
	int n, m;
	int freq[1001] = {};
	int seq[50];

	scanf("%d", &n);

	m = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", seq + i);
		freq[seq[i]]++;
		if(freq[seq[i]] == 1) m++;
	}

	printf("%d\n", m);
	for(int i = 0; i < n; ++i)
	{
		if(freq[seq[i]] == 1)
			printf("%d ", seq[i]);

		freq[seq[i]]--;
	}
	
	printf("\n");

	return 0;
}

