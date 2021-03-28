#include <cstdio>

int main()
{
	int two_gram[27][27] = {};
	int n;
	char str[128];

	scanf("%d %s", &n, str);
	n--;
	for(int i = 0; i < n; ++i)
		two_gram[str[i] - 'A'][str[i + 1] - 'A']++;

	int a, b;
	a = b = 0;
	for(int i = 0; i < 27; ++i)
	for(int j = 0; j < 27; ++j)
		if(two_gram[i][j] > two_gram[a][b])
		{
			a = i;
			b = j;
		}

	printf("%c%c\n", a + 'A', b + 'A');

	return 0;
}

