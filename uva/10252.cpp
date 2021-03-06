// 10252 - Common Permutation

#include <cstdio>
#include <cstring>

#define N 1002

int main()
{
	char A[N], B[N];
	int HA[27], HB[27];

	while(fgets(A, N, stdin) && fgets(B, N, stdin))
	{
		memset(HA, 0, sizeof(HA));
		memset(HB, 0, sizeof(HB));

		for(int i = 0; A[i] != '\n'; ++i)
			HA[A[i] - 'a']++;
		for(int i = 0; B[i] != '\n'; ++i)
			HB[B[i] - 'a']++;

		for(int i = 0; i < 27; ++i)
			while(HA[i]-- && HB[i]--) putchar(i + 'a');

		putchar('\n');
	}

	return 0;
}

