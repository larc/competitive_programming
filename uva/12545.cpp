// 12545 - Bits Equalizer

#include <cstdio>

int main()
{
	int n, swap[2], change[2];
	char S[101];
	char T[101];

	scanf("%d", &n);
	for(int c = 1; c <= n; ++c)
	{
		scanf("%s", S);
		scanf("%s", T);

		swap[0] = swap[1] = 0;
		change[0] = change[1] = 0;
		for(int i = 0; S[i]; ++i)
		{
			if(S[i] == T[i]) continue;

			S[i] == '?' ? ++change[T[i] - '0'] : ++swap[S[i] - '0'];
		}

		printf("Case %d: %d\n", c, swap[1] > swap[0] + change[1] ? -1 : change[0] + change[1] + swap[0] + (swap[1] > swap[0] ? swap[1] - swap[0] : 0));
	}

	return 0;
}

