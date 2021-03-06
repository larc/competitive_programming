// 193. Omar Loves Candies, Again

#include <cstdio>
#include <cstring>

int main()
{
	int alph[27], n_cases, m;
	char str[101];

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%s", str);

		memset(alph, 0, sizeof(alph));
		for(int i = 0; str[i]; ++i)
			alph[str[i] - 'a']++;

		m = 0;
		for(int i = 1; i < 27; ++i)
			if(alph[m] < alph[i]) m = i;

		printf("%d %c\n", alph[m], m + 'a');
	}

	return 0;
}

