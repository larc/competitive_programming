#include <cstdio>

int main()
{
	int n;
	char S[100'001];

	scanf("%d %s", &n, S);

	n = 1;
	for(int i = 1; S[i]; ++i)
		if(S[i] != S[i - 1]) ++n;

	printf("%d\n", n);

	return 0;
}

